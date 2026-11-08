--- hatch_build.py.orig	2026-09-22 06:41:03 UTC
+++ hatch_build.py
@@ -17,7 +17,6 @@ from babel.messages.pofile import read_po
 
 from babel.messages.mofile import write_mo
 from babel.messages.pofile import read_po
-from hatchling.builders.config import BuilderConfig
 from hatchling.builders.hooks.plugin.interface import BuildHookInterface
 
 if TYPE_CHECKING:  # pragma: no cover
@@ -73,7 +72,7 @@ def _compile_translations(root: Path) -> None:
             write_mo(target.open("wb"), catalog)
 
 
-class FavaBuildHook(BuildHookInterface[BuilderConfig]):
+class FavaBuildHook(BuildHookInterface):
     """Build hook to compile the frontend and the translations."""
 
     @override
