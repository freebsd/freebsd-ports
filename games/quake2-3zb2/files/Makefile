# $FreeBSD$

SHLIB=		game
SHLIB_NAME=	game.so

SRCS=		bot.c \
		bot.h \
		bot_fire.c \
		bot_func.c \
		bot_za.c \
		botstr.h \
		g_chase.c \
		g_cmds.c \
		g_combat.c \
		g_ctf.c \
		g_ctf.h \
		g_func.c \
		g_items.c \
		g_local.h \
		g_main.c \
		g_misc.c \
		g_monster.c \
		g_phys.c \
		g_save.c \
		g_spawn.c \
		g_svcmds.c \
		g_target.c \
		g_trigger.c \
		g_turret.c \
		g_utils.c \
		g_weapon.c \
		game.h \
		m_move.c \
		m_player.h \
		p_client.c \
		p_hud.c \
		p_menu.c \
		p_menu.h \
		p_trail.c \
		p_view.c \
		p_weapon.c \
		q_shared.c \
		q_shared.h

CFLAGS+=	-Dstricmp=strcasecmp -ffast-math -funroll-loops \
		-fomit-frame-pointer -fexpensive-optimizations

LDFLAGS+=	-L/lib -L/usr/lib -lm

.include <bsd.lib.mk>
