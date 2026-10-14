--- sources/TerminalStrip/physicalterminal.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/TerminalStrip/physicalterminal.cpp
@@ -131,7 +131,7 @@ bool PhysicalTerminal::setLevelOf(const QSharedPointer
 	if (i >= 0)
 	{
 #if QT_VERSION >= QT_VERSION_CHECK(5,14,0)
-		m_real_terminal.swapItemsAt(i, std::min(level, m_real_terminal.size()-1));
+		m_real_terminal.swapItemsAt(i, std::min<int>(level, static_cast<int>(m_real_terminal.size())-1));
 #else
 		auto j = std::min(level, m_real_terminal.size()-1);
 		std::swap(m_real_terminal.begin()[i], m_real_terminal.begin()[j]);
