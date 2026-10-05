There is no @ff-labs/fff-bun native build for FreeBSD, so drop the hard
import and use the graceful "unavailable" path that already exists.

--- packages/core/src/filesystem/fff.bun.ts.orig
+++ packages/core/src/filesystem/fff.bun.ts
@@ -1,4 +1,3 @@
-import { FileFinder } from "@ff-labs/fff-bun"
 import { bind } from "./fff.js"
 
 export type { Directory, DirSearch, File, Init, Mixed, MixedSearch, Picker, Result, Search } from "./fff.js"
@@ -7,7 +6,7 @@
   const FFF_LIBC: "gnu" | "musl"
 }
 
-const adapter = bind(FileFinder)
+const adapter = bind(undefined, "fff is unavailable on this platform")
 
 export const available = adapter.available
 export const create = adapter.create
