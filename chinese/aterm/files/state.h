/*
	Copyright (C) 1994	Edward Der-Hua Liu, Hsin-Chu, Taiwan
*/

typedef struct {
	char  kb_state;
        char _CurInMethod;
} InmdState;

#define EngChiMask (1)
#define HalfFullMask (2)

typedef struct {
	int len;
	int status;
	InmdState inmdstate;
	char tkey[512];
} XCIN_RES;

#define EngChi ((inmdstate.kb_state & EngChiMask) ? 1:0)
#define HalfFull ((inmdstate.kb_state & HalfFullMask) ? 1:0)
#define CurInMethod (inmdstate._CurInMethod)
/* extern InmdState inmdstate; */
