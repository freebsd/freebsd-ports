--- apps/openmw/mwgui/tooltips.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/tooltips.cpp
@@ -168,7 +168,7 @@ namespace MWGui
                         return;
                 }
 
-                std::string type = focus->getUserString("ToolTipType");
+                auto type = focus->getUserString("ToolTipType");
 
                 if (type == "")
                 {
@@ -224,7 +224,7 @@ namespace MWGui
                     ToolTipInfo info;
 
                     const ESM::Spell *spell =
-                        MWBase::Environment::get().getWorld()->getStore().get<ESM::Spell>().find(focus->getUserString("Spell"));
+                        MWBase::Environment::get().getWorld()->getStore().get<ESM::Spell>().find(std::string{focus->getUserString("Spell")});
                     info.caption = spell->mName;
                     Widgets::SpellEffectList effects;
                     for (const ESM::ENAMstruct& spellEffect : spell->mEffects.mList)
@@ -248,7 +248,7 @@ namespace MWGui
                         int school = MWMechanics::getSpellSchool(spell, player);
                         info.text = "#{sSchool}: " + sSchoolNames[school];
                     }
-                    std::string cost = focus->getUserString("SpellCost");
+                    auto cost = focus->getUserString("SpellCost");
                     if (cost != "" && cost != "0")
                         info.text += MWGui::ToolTips::getValueString(MWMechanics::calcSpellCost(*spell), "#{sCastCost}");
                     info.effects = effects;
@@ -262,7 +262,7 @@ namespace MWGui
 
                     tooltip->setVisible(true);
 
-                    std::map<std::string, std::string> userStrings = focus->getUserStrings();
+                    auto userStrings = focus->getUserStrings();
                     for (auto& userStringPair : userStrings)
                     {
                         size_t underscorePos = userStringPair.first.find('_');
