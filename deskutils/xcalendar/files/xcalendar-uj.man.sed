.de EX		\"Begin example
.ne 5
.if n .sp 1
.if t .sp .5
.nf
.in +.5i
..
.de EE
.fi
.in -.5i
.if n .sp 1
.if t .sp .5
..
.TH xcalendar 1 "6 June 1994" "X Version 11"
.SH 名称
xcalendar - X11 用のカレンダーとメモ
.SH 書式
.PP
\fBxcalendar \fP[month \fp[year\fp]\fP]
.PP
.SH 解説
.PP
\fIxcalendar\fP はメモ機能を持ったシンプルな対話型カレンダープログラムです。
このプログラムは X Toolkit と Athena または Motif ウィジェット
(コンパイル時のオプションで指定) で作られています。
.PP
コマンドラインで month と year が指定されなかった場合には
現在の年と月が仮定されます。
.PP
.SH 操作
.PP
日付の上でマウスの左ボタンをクリックするとテキストエディタが起動し、
テキストの編集や保存ができます。このテキストはその日付に関連づけられ、
後からエディタで開いて読み書きできます。
テキストは calendarDir リソースで指定されたディレクトリ (デフォルトでは
~/Calendar) に保存されます。エディタからは個々の日付に関連づけられた内容を
消去することもできます。またエディタ上で日付ラベルの左右にある矢印を
クリックすれば日の移動ができます。既に開いている日に移動した場合は、
メッセージが表示され、エディタは表示しかできないモードになります。
.PP
同様にメインウィンドウにおいて今日の日付ラベルの左右にある矢印を
クリックすることにより、月を移動することもできます。
.PP
ShowEntries 関数を実行すると、その月にある全ての予定をハイライト表示できます。
デフォルトではこの関数は (年や月が表示されている) タイトルウィンドウの中で
マウスの左ボタンを押すことにより実行されます。
もう一度押すと全ての予定のハイライト表示を止めます。
.PP
「祝日」は日エディタの下の方にあるテキストウィジェットに表示されます。
祝日は祝日ファイル (下記の holidayfile 参照) から読み取られます。
ファイルの形式は mm/dd/yyyy 祝日内容 で、日付と内容の間はタブで区切られます。
現在のところワイルドカードは使えません。
.SH 欠けている機能
.PP
いろいろ便利な機能が考えられるでしょう。たとえば今日の予定を自動的に
解釈して約束を検索し、適切な時間にアラーム (リマインダ) を鳴らすという機能が
考えられます。実際、このような機能を実現する \fIxcalendar+\fP という perl 
スクリプトがあります。おそらくある日には \fIxcalendar\fP はこの機能を
内蔵するでしょう。
.PP
.SH リソース
.PP
リソースデータベースはプログラムの見栄えを変更します。
フォントや縁幅、ラベル、その他のウィジェットで試用されているリソースが変更可能で
す。この機能の使い途の一つは曜日や月名の変更です。
.PP
変更可能な様々のリソースのウィジェット名には以下のようなものがあります。
.PP
.EX 0
XCalendar    - アプリケーションクラス
xcalendar    - トップレベルペイン
controls     - コントロールパネル
quitButton   - 終了ボタン
helpButton   - ヘルプボタン
date         - 日付ラベル
calendar     - カレンダーぺイン
daynumbers   - 日付フレーム
1-49         - 日付ボタン
daynames     - 曜日フレーム
MON,TUE,WED,THU,FRI,SAT,SUN - 曜日ボタン
helpWindow   - ヘルプウィンドウ
bcontrols    - 月ボタンフレーム
prev         - 先月ボタン
succ         - 来月ボタン
cdate        - 今日の日付ウィジェット
dayEditor    - エディタポップアップ
editorFrame  - エディタフレーム
editorTitle  - エディタタイトル
editor       - エディタ
holiday      - 祝日テキスト
daybuttons   - 日付ボタンフレーム
prevday      - 前日ボタン
succday      - 明日ボタン
editorControls - コントロールパネル
doneButton   - 終了ボタン
saveButton   - 保存ボタン
clearEntry   - 消去ボタン
.EE
.PP
アプリケーション特有リソース:
.PP
.EX 0
reverseVideoMark  - True の場合は予定を反転した強調表示にします。
                    デフォルトでは白黒ディスプレイでは True で、
                    カラーディスプレイでは Falase です。

setMarkBackground - True かつ reverseVideoMark が False の場合、
                    予定の強調表示は背景色が markBackground に
                    なります。

markBackground    - 予定を強調表示する際に使われる背景色。

setMarkForeground - setMarkBackground と同様です。

markForeground    - 予定を強調表示する際に使われる前景色。

\fIsetMarkBackground\fP と \fIsetMarkForeground\fP の組合わせは
どのような値でも構いません。


january,february,..,december - これらのリソースで月ラベルの月名や
                    oldStyle (下記参照) 時のファイル名決定方法を
                    変更できます。

firstDay          - 1-7 の整数で週をどの曜日から始めるか指定します。
                    デフォルトは 7 (日曜) です。

markOnStartup     - True の場合起動時から予定をマークします。
                    デフォルト: True。
.\" 原文は False

helpFile          - xcalendar.hlp ファイルのフルパス名。
                    デフォルト: %%XCALENDAR_LIBDIR%%/xcalendar.hlp

textBufferSize    - 日付エディタのテキストバッファの最大サイズ。
                    デフォルト: 2048。

calendarDir       - $HOME/Calendar 以外のディレクトリにカレンダー
                    ファイルを保存する場合のパス名

holidayFile       - 祝日を決めるのに用いるファイルのパス名。
                    デフォルト: %%XCALENDAR_LIBDIR%%/xcalendar.hol

oldStyle          - ファイルの命名規則として新しいスタイル
                    (xcyyyymmdd) ではなく version 3.0 およびそれ
                    以前のファイル命名規則 (xcDAYmonYEAR) を使用
                    します。ここで DAY と YEAR は数字で mon は月
                    の最初の3文字です。
                    デフォルト: True

markCurrent       - True の場合、今日の日付をマークします (見ら
                    れる場合。カラーディスプレイでのみ便利です)。
                    デフォルト: False

updateCurrent     - 今日の日付のマーキングを更新する間隔の秒数。
                    デフォルト: 60

currentForeground - 今日の日付を強調表示する際の前景色。

markHoliday       - True の場合、祝日をマークします (見られる場合、
                    カラーディスプレイでのみ便利です)。
                    デフォルト: False

holidayForeground - 祝日を強調表示する際の前景色

monthnames        - cdate において日付をフォーマットする際に用いる
                    月名を '/' で区切った文字列

monthnms          - cdate において日付をフォーマットする際に用いる
                    月名の略称を '/' で区切った文字列

daynames          - cdate において日付をフォーマットする際に用いる
                    曜日名を '/' で区切った文字列

daynms            - cdate において日付をフォーマットする際に用いる
                    曜日名の略称を '/' で区切った文字列

date              - cdate において日付をフォーマットする文字列。
                    解釈されるフォーマット文字は次のとおり:

.in +9
.nf
%W      曜日の完全な名称
%w      曜日の略称
%M      月名の完全な名称
%m      月名の略称
%d      日 (数字)
%Y      完全な年数 (4 桁)
%y      2 桁の年数
.fi
.in -9

                    デフォルト: "%W, %M %d";
.EE
.SH デフォルトのリソースデータベース
.EX 0
*international: TRUE
!
*showGrip:		False
*calendar*internalBorderWidth: 0
*input:		True
*controls*resize: False
*bcontrols*resize: False
*daybuttons*resize: False
*resizable: True
*title: XCalendar v.4.0
*dayEditor.title: Day Editor
*helpWindow.title: XCalendar Help
*Font: 8x13
*FontList: 8x13

*helpFile:	%%XCALENDAR_LIBDIR%%/xcalendar.hlp
*holidayFile:   %%XCALENDAR_LIBDIR%%/xcalendar.hol

*firstDay:		7

*labelType: XmSTRING
*prev*Label: 先月
*succ*Label: 来月
*prevday*Label: 昨日
*succday*Label: 明日
*helpButton*Label: 助け
*quitButton*Label: 終り

*daynames.SUN.label: \\ 日
*daynames.MON.label: \\ 月
*daynames.TUE.label: \\ 火
*daynames.WED.label: \\ 水
*daynames.THU.label: \\ 木
*daynames.FRI.label: \\ 金
*daynames.SAT.label: \\ 土

*monthnames:	1/2/3/4/5/6/7/8/9/10/11/12
*monthnms:	1/2/3/4/5/6/7/8/9/10/11/12
*daynames:	日曜日/月曜日/火曜日/水曜日/木曜日/金曜日/土曜日
*daynms:	日/月/火/水/木/金/土                            
*date:		%M月%d日(%W)


#ifdef COLOR
! colors
*Background: lightgray
*markBackground: Steel Blue
*daynames*Background: lightgray
*daynames.SUN*Foreground: Red
*daynames.SAT*Foreground: Black
*daynumbers*Foreground:   Black
*daynumbers.1*Foreground: Red
*daynumbers.8*Foreground: Red
*daynumbers.15*Foreground: Red
*daynumbers.22*Foreground: Red
*daynumbers.29*Foreground: Red
*daynumbers.36*Foreground: Red
*helpButton*Background: slategray
*helpButton*Foreground: White
*quitButton*Background: slategray
*quitButton*Foreground: White
*editorTitle*Background: lightgray
*editorTitle*Foreground: Black
*editorControls*Background: lightgray
*editorControls*Command.Background: slategray
*editorControls*Command.Foreground: White
*editorControls*XmPushButton.Background: slategray
*editorControls*XmPushButton.Foreground: White
#endif

*setMarkBackground: True
*markOnStartup: True
*markCurrent: True
*currentForeground: Blue
*markHoliday: True
*holidayForeground: Red

*BorderWidth:		2
*calendar.borderWidth:	1
*borderWidth: 0
*date*borderWidth: 0
*date*vertDistance: 1
*prev*vertDistance: 0
*succ*vertDistance: 0

*controls*date*fontSet:		8x13bold, -*--14-*
*daynames*fontSet:			-*--14-*
*dayEditor*editorTitle*fontSet:	8x13bold, -*--14-*
*helpWindow*editorTitle*fontSet:	8x13bold, -*--14-*

*helpButton*vertDistance: 5
*quitButton*vertDistance: 5
*editorTitle*vertDistance: 5
*cdate*vertDistance: 5

*editorControls*doneButton*label: 終り
*editorControls*saveButton*label: 保存
*editorControls*clearEntry*label: 消えてなくなれ
*doneButton*labelString: 終り
*saveButton*labelString: 保存
*clearEntry*labelString: 消えてなくなれ

*dayEditor*geometry: 300x150
*helpWindow*geometry: 600x350

*dayEditor*fontSet:			-*--14-*
*controls*fontSet:			-*--14-*
*bcontrols*fontSet:			-*--14-*
*editorControls*fontSet:		-*--14-*
*fontSet: 				-*--14-*

!*preeditType: Root
!*preeditType: OffTheSpot
*preeditType: OverTheSpot

*helpWindow*editorTitle*label: ヘルプ
*helpWindow*editorTitle*labelString: ヘルプ
*helpWindow*rows: 15
*helpWindow*columns: 80
*rows:7
*columns: 30

*dayEditor*Paned*editor.width: 300
*dayEditor*Paned*editor.height: 150
*helpWindow*Paned*editor.width: 600
*helpWindow*Paned*editor.height: 350

*bcontrols*borderWidth: 0
*prev*highlightThickness: 0
*succ*highlightThickness: 0

*prevday*highlightThickness: 0
*succday*highlightThickness: 0
*daybuttons*borderWidth: 0

*Scrollbar.borderWidth: 1
*Text*scrollVertical: whenNeeded
*scrollHorizontal: Never
*helpWindow*scrollHorizontal: Always
*holiday*cursorPositionVisible: False
*holiday*displayCaret: False
*helpWindow*cursorPositionVisible: False
*helpWindow*displayCaret: False

! Keyboard accelerators
*editorControls*doneButton*accelerators: #override \\n\\
	Meta<Key>q: set() notify() reset() \\n
*editorControls*saveButton*accelerators: #override \\n\\
	Meta<Key>s: set() notify() reset() \\n
*editorControls*clearEntry*accelerators: #override \\n\\
	Meta<Key>c: set() notify() reset() \\n

*daybuttons*prevday*accelerators: #override \\n\\
	Meta<Key>p: set() notify() reset() \\n
*daybuttons*succday*accelerators: #override \\n\\
	Meta<Key>n: set() notify() reset() \\n

*prev*accelerators: #override \\n\\
	<Key>p: set() notify() reset() \\n
*succ*accelerators: #override \\n\\
	<Key>n: set() notify() reset() \\n
*quitButton*accelerators: #override \\n\\
	<Key>q: set() notify() \\n

*XmText.translations: #override\\n\\
.in +9
.nf
Ctrl <Key>b:            backward-character()\\n\\
Alt <Key>b:             backward-word()\\n\\
Meta <Key>b:            backward-word()\\n\\
Shift Alt <Key>b:       backward-word(extend)\\n\\
Shift Meta <Key>b:      backward-word(extend)\\n\\
Alt <Key>[:             backward-paragraph()\\n\\
Meta <Key>[:            backward-paragraph()\\n\\
Shift Alt <Key>[:       backward-paragraph(extend)\\n\\
Shift Meta <Key>[:      backward-paragraph(extend)\\n\\
Alt <Key><:             beginning-of-file()\\n\\
Meta <Key><:            beginning-of-file()\\n\\
Ctrl <Key>a:            beginning-of-line()\\n\\
Shift Ctrl <Key>a:      beginning-of-line(extend)\\n\\
Ctrl <Key>osfInsert:    copy-clipboard()\\n\\
Shift <Key>osfDelete:   cut-clipboard()\\n\\
Shift <Key>osfInsert:   paste-clipboard()\\n\\
Alt <Key>>:             end-of-file()\\n\\
Meta <Key>>:            end-of-file()\\n\\
Ctrl <Key>e:            end-of-line()\\n\\

Shift Ctrl <Key>e:      end-of-line(extend)\\n\\
Ctrl <Key>f:            forward-character()\\n\\
Alt <Key>]:             forward-paragraph()\\n\\
Meta <Key>]:            forward-paragraph()\\n\\
Shift Alt <Key>]:       forward-paragraph(extend)\\n\\
Shift Meta <Key>]:      forward-paragraph(extend)\\n\\
Ctrl Alt <Key>f:        forward-word()\\n\\
Ctrl Meta <Key>f:       forward-word()\\n\\
Ctrl <Key>d:            kill-next-character()\\n\\
Ctrl <Key>h:            kill-previous-character()\\n\\
Alt <Key>BackSpace:     kill-previous-word()\\n\\
Meta <Key>BackSpace:    kill-previous-word()\\n\\
Ctrl <Key>w:            key-select() kill-selection()\\n\\
Ctrl <Key>y:            unkill()\\n\\
Ctrl <Key>k:            kill-to-end-of-line()\\n\\
Alt <Key>Delete:        kill-to-start-of-line()\\n\\
Meta <Key>Delete:       kill-to-start-of-line()\\n\\
Ctrl <Key>o:            newline-and-backup()\\n\\
Ctrl <Key>j:            newline-and-indent()\\n\\
Ctrl <Key>n:            next-line()\\n\\
Ctrl <Key>osfLeft:      page-left()\\n\\
Ctrl <Key>osfRight:     page-right()\\n\\
Ctrl <Key>p:            previous-line()\\n\\
Ctrl <Key>g:            process-cancel()\\n\\
Ctrl <Key>l:            redraw-display()\\n\\
Ctrl <Key>v:            next-page()\\n\\
Meta <Key>v:            previous-page()\\n\\
Ctrl <Key>osfDown:      next-page()\\n\\
Ctrl <Key>osfUp:        previous-page()\\n\\
Ctrl <Key>space:        set-anchor()\\n
.fi 
.in -9 
.EE
.SH 関連ファイル
.PP
$HOME/Calendar/*, %%XCALENDAR_LIBDIR%%/xcalendar.hlp,
%%XCALENDAR_LIBDIR%%/xcalendar.hol
.PP
.SH 関連項目
xrdb(1), xcalendar+(1)
.PP
.SH バグ
.PP
いくつかあると思います。
もし見つけたら私 (bingle@cs.purdue.edu) に教えてください。
.PP
.SH 作者
.PP
Copyright 1988 by Massachusetts Institute of Technology
.br
Roman J. Budzianowski, MIT Project Athena

Copyright 1990-1994 by Purdue University
.br
Richard Bingle, Department of Computer Sciences

拡張 / 提案:
.br
Beth Chaney
.br
Purdue University, Department of Computer Sciences

Mike Urban
.br
Jet Propulsion Labs, NASA

Joel Neisen
.br
Minnesota Supercomputer Center

Hiroshi Kuribayashi
.br
Omron Corp.
