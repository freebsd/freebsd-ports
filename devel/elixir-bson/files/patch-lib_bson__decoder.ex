--- lib/bson_decoder.ex.orig	2021-02-27 04:49:09 UTC
+++ lib/bson_decoder.ex
@@ -51,7 +51,7 @@ defmodule Bson.Decoder do
 
   ```
   """
-  def elist_to_hashdict(elist), do: elist |> Enum.reduce %HashDict{}, fn({k, v}, h) -> HashDict.put(h, k, v) end
+  def elist_to_hashdict(elist), do: elist |> Enum.reduce(%HashDict{}, fn({k, v}, h) -> HashDict.put(h, k, v) end)
 
   @doc """
   Transform an elist to a Keyword
@@ -62,7 +62,7 @@ defmodule Bson.Decoder do
 
   ```
   """
-  def elist_to_keyword(elist), do: elist |> Enum.map fn({k, v}) -> {String.to_atom(k), v} end
+  def elist_to_keyword(elist), do: elist |> Enum.map(fn({k, v}) -> {String.to_atom(k), v} end)
 
   @doc """
   Identity function
@@ -91,7 +91,7 @@ defmodule Bson.Decoder do
   ...>  %{a: "r"},
   ...>  %{a: ""},
   ...>  %{a: 1, b: 5}
-  ...> ] |> Enum.all? fn(term) -> assert term == term |> Bson.encode |> Bson.decode end
+  ...> ] |> Enum.all?(fn(term) -> assert term == term |> Bson.encode |> Bson.decode end)
   true
 
   iex> term = %{
