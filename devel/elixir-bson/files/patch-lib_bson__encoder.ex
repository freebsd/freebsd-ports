--- lib/bson_encoder.ex.orig	2021-02-27 04:48:02 UTC
+++ lib/bson_encoder.ex
@@ -1,32 +1,33 @@
-defmodule Bson.Encoder do
-  defprotocol Protocol do
-    @moduledoc """
-    `Bson.Encoder.Protocol` protocol defines Bson encoding according to Elxir terms and some Bson predefined structs (see `Bson`).
+defprotocol Bson.Encoder.Protocol do
+  @moduledoc """
+  `Bson.Encoder.Protocol` protocol defines Bson encoding according to Elxir terms and some Bson predefined structs (see `Bson`).
 
-    List of the protocol implementations:
+  List of the protocol implementations:
 
-    * `Map` - Encodes a map into a document
-    * `HasDict` - Encodes a HashDict into a document
-    * `Keyword` - Encodes a Keyword into a document
-    *  `List` - Encodes a list of key-alue pairs into a document otherwize encode list into array
-    * `Integer` - Encodes integer in 32 or 64 bits
-    * `Float` - Encodes float in 64 bits
-    * `Atom` - Encodes special atom (`false`, `true`, `nil`,
-    `:nan`, `:+inf`, `:-inf`, `MIN_KEY` and `MAX_KEY`) in appropriate format
-    others in special type Symbol
-    * `BitString` - as binary string
-    * `Bson.Regex' - see specs
-    * `Bson.ObjectId' - see specs
-    * `Bson.JS' - see specs
-    * `Bson.Bin' - see specs
-    * `Bson.Timestamp  ' - see specs
-    """
+  * `Map` - Encodes a map into a document
+  * `HasDict` - Encodes a HashDict into a document
+  * `Keyword` - Encodes a Keyword into a document
+  *  `List` - Encodes a list of key-alue pairs into a document otherwize encode list into array
+  * `Integer` - Encodes integer in 32 or 64 bits
+  * `Float` - Encodes float in 64 bits
+  * `Atom` - Encodes special atom (`false`, `true`, `nil`,
+  `:nan`, `:+inf`, `:-inf`, `MIN_KEY` and `MAX_KEY`) in appropriate format
+  others in special type Symbol
+  * `BitString` - as binary string
+  * `Bson.Regex' - see specs
+  * `Bson.ObjectId' - see specs
+  * `Bson.JS' - see specs
+  * `Bson.Bin' - see specs
+  * `Bson.Timestamp  ' - see specs
+  """
 
-    @doc """
-    Returns a binary representing a term in Bson format
-    """
-    def encode(term)
-  end
+  @doc """
+  Returns a binary representing a term in Bson format
+  """
+  def encode(term)
+end
+
+defmodule Bson.Encoder do
   defmodule Error do
     @moduledoc """
     Container for error messages
@@ -56,7 +57,7 @@ defmodule Bson.Encoder do
     end
   end
 
-  defimpl Protocol, for: Integer do
+  defimpl Bson.Encoder.Protocol, for: Integer do
     @doc """
     iex> Bson.Encoder.Protocol.encode(2)
     {<<16>>, <<2, 0, 0, 0>>}
@@ -73,7 +74,7 @@ defmodule Bson.Encoder do
     def encode(i), do: %Error{what: [Integer], term: i}
   end
 
-  defimpl Protocol, for: Float do
+  defimpl Bson.Encoder.Protocol, for: Float do
     @doc """
     iex> Bson.Encoder.Protocol.encode(1.1)
     {<<1>>, <<154, 153, 153, 153, 153, 153, 241, 63>>}
@@ -81,7 +82,7 @@ defmodule Bson.Encoder do
     def encode(f), do: {<<0x01>>, <<(f)::size(64)-float-little>>}
   end
 
-  defimpl Protocol, for: Atom do
+  defimpl Bson.Encoder.Protocol, for: Atom do
     @doc """
     iex> Bson.Encoder.Protocol.encode(true)
     {<<8>>, <<1>>}
@@ -114,7 +115,7 @@ defmodule Bson.Encoder do
     def encode(atom),    do: {<<0x0e>>, (atom |> Atom.to_string |> Bson.Encoder.wrap_string)}
   end
 
-  defimpl Protocol, for: Bson.UTC do
+  defimpl Bson.Encoder.Protocol, for: Bson.UTC do
     @doc """
     iex> Bson.Encoder.Protocol.encode(Bson.UTC.from_now({1390, 324703, 518471}))
     {<<9>>, <<30, 97, 207, 181, 67, 1, 0, 0>>}
@@ -123,7 +124,7 @@ defmodule Bson.Encoder do
     def encode(utc), do: %Error{what: [Bson.UTC], term: utc}
   end
 
-  defimpl Protocol, for: Bson.Regex do
+  defimpl Bson.Encoder.Protocol, for: Bson.Regex do
     @doc """
     iex> Bson.Encoder.Protocol.encode(%Bson.Regex{pattern: "p", opts: "i"})
     {<<11>>, ["p", <<0>>, "i", <<0>>]}
@@ -132,7 +133,7 @@ defmodule Bson.Encoder do
     def encode(regex), do: %Error{what: [Bson.Regex], term: regex}
   end
 
-  defimpl Protocol, for: Bson.ObjectId do
+  defimpl Bson.Encoder.Protocol, for: Bson.ObjectId do
     @doc """
     iex> Bson.Encoder.Protocol.encode(%Bson.ObjectId{oid: <<0xFF>>})
     {<<0x07>>, <<255>>}
@@ -144,7 +145,7 @@ defmodule Bson.Encoder do
     def encode(oid), do: %Error{what: [Bson.ObjectId], term: oid}
   end
 
-  defimpl Protocol, for: Bson.JS do
+  defimpl Bson.Encoder.Protocol, for: Bson.JS do
     @doc """
     iex> Bson.Encoder.Protocol.encode(%Bson.JS{code: "1+1;"})
     {<<13>>, [<<5, 0, 0, 0>>, "1+1;", <<0>>]}
@@ -166,7 +167,7 @@ defmodule Bson.Encoder do
     defp js_ctx(jsctx), do: <<(byte_size(jsctx)+4)::32-little-signed, jsctx::binary>>
   end
 
-  defimpl Protocol, for: Bson.Bin do
+  defimpl Bson.Encoder.Protocol, for: Bson.Bin do
     @doc """
     iex> Bson.Encoder.Protocol.encode(%Bson.Bin{bin: "e", subtype: Bson.Bin.subtyx(:user)})
     {<<5>>,[<<1, 0, 0, 0>>, 128, "e"]}
@@ -178,7 +179,7 @@ defmodule Bson.Encoder do
     def encode(bin, subtype), do: %Error{what: [Bson.Bin], term: {bin, subtype}}
   end
 
-  defimpl Protocol, for: Bson.Timestamp do
+  defimpl Bson.Encoder.Protocol, for: Bson.Timestamp do
     @doc """
     iex> Bson.Encoder.Protocol.encode(%Bson.Timestamp{inc: 1, ts: 2})
     {<<17>>,<<1, 0, 0, 0, 2, 0, 0, 0>>}
@@ -190,7 +191,7 @@ defmodule Bson.Encoder do
       def encode(ts), do: %Error{what: [Bson.Timestamp], term: ts}
   end
 
-  defimpl Protocol, for: BitString do
+  defimpl Bson.Encoder.Protocol, for: BitString do
     @doc """
     iex> Bson.Encoder.Protocol.encode("a")
     {<<2>>, [<<2, 0, 0, 0>>, "a", <<0>>]}
@@ -199,7 +200,7 @@ defmodule Bson.Encoder do
     def encode(bits), do: %Error{what: [BitString], term: bits}
   end
 
-  defimpl Protocol, for: List do
+  defimpl Bson.Encoder.Protocol, for: List do
     @doc """
     iex> Bson.Encoder.Protocol.encode([])
     {<<4>>,<<5, 0, 0, 0, 0>>}
@@ -241,7 +242,7 @@ defmodule Bson.Encoder do
     end
   end
 
-  defimpl Protocol, for: [Map, HashDict, Keyword] do
+  defimpl Bson.Encoder.Protocol, for: [Map, HashDict, Keyword] do
     @doc """
     # Map
     iex> Bson.Encoder.Protocol.encode(%{})
