# New ports collection makefile for:	anope
# Date created:		13/04/2004
# Whom:			mat
#
# $FreeBSD$
#

PORTNAME=	anope
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A set of IRC services for IRC networks

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=	yes

# OPTIONS --{{{
OPTIONS=	MYSQL "Use mysql" ON \
		MODULES "Use modules" ON \
		MD5 "Encrypt passwords" ON \
		THREAD "Build with threads (needed for proxy detector)" ON \
		DREAM "DreamForge 4.6.7 " OFF \
		BAHAMUT "Bahamut 1.4.27 [or later]" OFF \
		UNREAL "UnrealIRCd 3.1.1 [or later]" ON \
		ULT2 "UltimateIRCd 2.8.2 [or later]" OFF \
		ULT3 "UltimateIRCd 3.0.0 [alpha26 or later]" OFF \
		HYB "Hybrid IRCd 7.0 [experimental]" OFF \
		VIA "ViagraIRCd 1.3.x [or later]" OFF \
		PTL "PTlink 6.15.0 [experimental]" OFF
#}}}

ANOPEBIN?=	${PREFIX}/libexec/anope
ANOPEDAT?=	${DATADIR}
ANOPEMOD?=	${PREFIX}/lib/anope/
ANOPEUMASK?=	077

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/-D_REENTRANT/${PTHREAD_CFLAGS}/" \
		-e "s/-pthread/${PTHREAD_LIBS}/" \
		${WRKSRC}/configure

CONFIG_CACHE=${WRKSRC}/config.cache
pre-configure: #--{{{
	@${ECHO_CMD} PROGRAM=\"anope\" > ${CONFIG_CACHE}
	@${ECHO_CMD} BINDEST=\"${ANOPEBIN}\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} DATDEST=\"${ANOPEDAT}\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} UMASK=\"${ANOPEUMASK}\" >> ${CONFIG_CACHE}
.if defined(WITH_MYSQL)
	@${ECHO_CMD} MYSQL=\"USE_MYSQL\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} RDB=\"USE_RDB\" >> ${CONFIG_CACHE}
.endif
.if defined(WITH_MODULES)
	@${ECHO_CMD} USE_MODULES=\"USE_MODULES\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} MODULE_PATH=\"${ANOPEMOD}\" >> ${CONFIG_CACHE}
.endif
.if defined(WITH_MD5)
	@${ECHO_CMD} ENCRYPTION=\"ENCRYPT_MD5\" >> ${CONFIG_CACHE}
.endif
.if defined(WITH_THREAD)
	@${ECHO_CMD} THREAD=\"USE_THREADS\" >> ${CONFIG_CACHE}
.endif
.if defined(WITH_DREAM)
	@${ECHO_CMD} IRCTYPE=1 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_DREAMFORGE\" >> ${CONFIG_CACHE}
.elif defined(WITH_BAHAMUT)
	@${ECHO_CMD} IRCTYPE=2 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_BAHAMUT\" >> ${CONFIG_CACHE}
.elif defined(WITH_UNREAL)
	@${ECHO_CMD} IRCTYPE=3 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_DREAMFORGE\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF2=\"IRC_UNREAL\" >> ${CONFIG_CACHE}
.elif defined(WITH_ULT2)
	@${ECHO_CMD} IRCTYPE=4 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_DREAMFORGE\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF2=\"IRC_ULTIMATE\" >> ${CONFIG_CACHE}
.elif defined(WITH_ULT3)
	@${ECHO_CMD} IRCTYPE=5 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_BAHAMUT\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF2=\"IRC_ULTIMATE3\" >> ${CONFIG_CACHE}
.elif defined(WITH_HYB)
	@${ECHO_CMD} IRCTYPE=6 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_HYBRID\" >> ${CONFIG_CACHE}
.elif defined(WITH_VIA)
	@${ECHO_CMD} IRCTYPE=7 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_BAHAMUT\" >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF2=\"IRC_VIAGRA\" >> ${CONFIG_CACHE}
.elif defined(WITH_PTL)
	@${ECHO_CMD} IRCTYPE=8 >> ${CONFIG_CACHE}
	@${ECHO_CMD} IRCTYPE_DEF=\"IRC_PTLINK\" >> ${CONFIG_CACHE}
.endif
# XXX Add here other arch which needs -fPIC :-)
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
	@${ECHO_CMD} CC_FLAGS=\"${CFLAGS} -fPIC\" >> ${CONFIG_CACHE}
.else
	@${ECHO_CMD} CC_FLAGS=\"${CFLAGS}\" >> ${CONFIG_CACHE}
.endif
#}}}

pre-install:
	@${MKDIR} ${ANOPEBIN}
	@${MKDIR} ${ANOPEDAT}
	@${MKDIR} ${ANOPEMOD}

.include <bsd.port.post.mk>
