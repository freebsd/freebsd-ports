--- src/vs/platform/agentHost/node/copilot/copilotSessionWrapper.ts.orig	2026-07-02 12:32:09 UTC
+++ src/vs/platform/agentHost/node/copilot/copilotSessionWrapper.ts
@@ -16,7 +16,7 @@ export class CopilotSessionWrapper extends Disposable 
 
 	private readonly _handledEventTypes = new Set<SessionEventType>();
 	private readonly _onUnhandledEvent = this._register(new Emitter<SessionEvent>());
-	readonly onUnhandledEvent = this._onUnhandledEvent.event;
+	readonly onUnhandledEvent: Event<SessionEvent> = this._onUnhandledEvent.event;
 
 	constructor(readonly session: CopilotSession) {
 		super();
