{
fpvutils.pas

Vector graphics document

License: The same modified LGPL as the Free Pascal RTL
         See the file COPYING.modifiedLGPL for more details

AUTHORS: Felipe Monteiro de Carvalho
         Pedro Sol Pegorini L de Lima
}
unit fpvutils;

{$ifdef fpc}
  {$mode delphi}
{$endif}

interface

uses
  Classes, SysUtils, Math,
  fpvectorial, fpimage;

type
  T10Strings = array[0..9] of shortstring;

// Color Conversion routines
function FPColorToRGBHexString(AColor: TFPColor): string;
function RGBToFPColor(AR, AG, AB: byte): TFPColor; inline;
// Other routine
function CanvasCoordsToFPVectorial(AY: Integer; AHeight: Integer): Integer; inline;
function CanvasTextPosToFPVectorial(AY: Integer; ACanvasHeight, ATextHeight: Integer): Integer;
function SeparateString(AString: string; ASeparator: char): T10Strings;

implementation

{@@ This function is utilized by the SVG writer and some other places, so
    it shouldn't be changed.
}
function FPColorToRGBHexString(AColor: TFPColor): string;
begin
  Result := Format('%.2x%.2x%.2x', [AColor.Red shr 8, AColor.Green shr 8, AColor.Blue shr 8]);
end;

function RGBToFPColor(AR, AG, AB: byte): TFPColor; inline;
begin
  Result.Red := (AR shl 8) + AR;
  Result.Green := (AG shl 8) + AG;
  Result.Blue := (AB shl 8) + AB;
  Result.Alpha := $FFFF;
end;

{@@ Converts the coordinate system from a TCanvas to FPVectorial
    The basic difference is that the Y axis is positioned differently and
    points upwards in FPVectorial and downwards in TCanvas.
    The X axis doesn't change. The fix is trivial and requires only the Height of
    the Canvas as extra info.

    @param AHeight Should receive TCanvas.Height
}
function CanvasCoordsToFPVectorial(AY: Integer; AHeight: Integer): Integer; inline;
begin
  Result := AHeight - AY;
end;

{@@
  LCL Text is positioned based on the top-left corner of the text.
  Besides that, one also needs to take the general coordinate change into account too.

  @param ACanvasHeight Should receive TCanvas.Height
  @param ATextHeight   Should receive TFont.Size
}
function CanvasTextPosToFPVectorial(AY: Integer; ACanvasHeight, ATextHeight: Integer): Integer;
begin
  Result := CanvasCoordsToFPVectorial(AY, ACanvasHeight) - ATextHeight;
end;

{@@
  Reads a string and separates it in substring
  using ASeparator to delimite them.

  Limits:

  Number of substrings: 10 (indexed 0 to 9)
  Length of each substring: 255 (they are shortstrings)
}
function SeparateString(AString: string; ASeparator: char): T10Strings;
var
  i, CurrentPart: integer;
begin
  CurrentPart := 0;

  { Clears the result }
  for i := 0 to 9 do
    Result[i] := '';

  { Iterates througth the string, filling strings }
  for i := 1 to Length(AString) do
  begin
    if Copy(AString, i, 1) = ASeparator then
    begin
      Inc(CurrentPart);

      { Verifies if the string capacity wasn't exceeded }
      if CurrentPart > 9 then
        Exit;
    end
    else
      Result[CurrentPart] := Result[CurrentPart] + Copy(AString, i, 1);
  end;
end;

end.

