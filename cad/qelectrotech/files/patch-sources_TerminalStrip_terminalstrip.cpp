--- sources/TerminalStrip/terminalstrip.cpp.orig	2026-01-28 12:19:13 UTC
+++ sources/TerminalStrip/terminalstrip.cpp
@@ -639,7 +639,7 @@ bool TerminalStrip::isBridgeable(const QVector<QShared
 		// Get the physical terminal and pos
 	auto first_physical_terminal = first_real_terminal->physicalTerminal();
 	QVector<shared_physical_terminal> physical_vector{first_physical_terminal};
-	QVector<int> pos_vector{m_physical_terminals.indexOf(first_physical_terminal)};
+	QVector<int> pos_vector{static_cast<int>(m_physical_terminals.indexOf(first_physical_terminal))};
 
 	auto bridge_ = isBridged(first_real_terminal);
 		//bool to know at the end of this function if at least one terminal is not bridged
