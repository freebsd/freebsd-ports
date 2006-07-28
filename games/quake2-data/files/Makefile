# $FreeBSD$

SHLIB=		game
SHLIB_NAME=	game.so

SRCS=		g_ai.c \
		g_chase.c \
		g_cmds.c \
		g_combat.c \
		g_func.c \
		g_items.c \
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
		m_actor.c \
		m_berserk.c \
		m_boss2.c \
		m_boss3.c \
		m_boss31.c \
		m_boss32.c \
		m_brain.c \
		m_chick.c \
		m_flash.c \
		m_flipper.c \
		m_float.c \
		m_flyer.c \
		m_gladiator.c \
		m_gunner.c \
		m_hover.c \
		m_infantry.c \
		m_insane.c \
		m_medic.c \
		m_move.c \
		m_mutant.c \
		m_parasite.c \
		m_soldier.c \
		m_supertank.c \
		m_tank.c \
		p_client.c \
		p_hud.c \
		p_trail.c \
		p_view.c \
		p_weapon.c \
		q_shared.c

CFLAGS+=	-Dstricmp=strcasecmp
.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-ffast-math -funroll-loops -fomit-frame-pointer \
		-fexpensive-optimizations
.endif

LDFLAGS+=	-L/lib -L/usr/lib -lm

.include <bsd.lib.mk>
