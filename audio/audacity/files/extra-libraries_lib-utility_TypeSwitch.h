--- libraries/lib-utility/TypeSwitch.h.orig	2023-11-16 11:58:21 UTC
+++ libraries/lib-utility/TypeSwitch.h
@@ -127,7 +127,7 @@ struct Executor {
          // Case 1: Compatible, and invocable on the next function, giving
          // another function, that accepts BaseClass:
          struct Case1_;
-         using Case1 = std::conjunction<Compatible, curried, Case1_>;
+         using Case1 = TypeList::conjunction<Compatible, curried, Case1_>;
          struct Case1_ {
             static constexpr bool value = std::is_invocable_v<
                std::invoke_result_t<F, Dummy &&>, BaseClass&, Args&&...>;
@@ -135,7 +135,7 @@ struct Executor {
          };
 
          // Case 2: Invocable directly on the object
-         struct Case2 : std::conjunction<
+         struct Case2 : TypeList::conjunction<
             Compatible, std::negation<curried>,
             std::is_invocable<F, BaseClass&, Args&&...>
          > {
