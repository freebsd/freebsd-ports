# New ports collection makefile for:	anope
# Date created:		13/04/2004
# Whom:			mat
#
# $FreeBSD$
#

PORTNAME=	anope
PORTVERSION=	1.6.2
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
# in that case, OPTIONS are ignored, no defaults
.if defined(PACKAGE_BUILDING) || defined(BATCH)
WITH_MYSQL=	yes
WITH_MODULES=	yes
WITH_MD5=	yes
WITH_THREAD=	yes
WITH_UNREAL=	yes
.endif
#}}}

ANOPEBIN?=	${PREFIX}/libexec/anope
ANOPEDAT?=	${DATADIR}
ANOPEMOD?=	${PREFIX}/lib/anope/
ANOPEUMASK?=	077

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64 (shared libraries must be compiled with -fPIC)"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Does not build on ia64"
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/-D_REENTRANT/${PTHREAD_CFLAGS}/" \
		-e "s/-pthread/${PTHREAD_LIBS}/" \
		${WRKSRC}/configure

pre-configure: #--{{{
	@${ECHO_CMD} PROGRAM="anope" > ${WRKSRC}/config.cache
	@${ECHO_CMD} BINDEST="${ANOPEBIN}" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} DATDEST="${ANOPEDAT}" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} UMASK="${ANOPEUMASK}" >> ${WRKSRC}/config.cache
.if defined(WITH_MYSQL)
	@${ECHO_CMD} MYSQL="USE_MYSQL" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} RDB="USE_RDB" >> ${WRKSRC}/config.cache
.endif
.if defined(WITH_MODULES)
	@${ECHO_CMD} USE_MODULES="USE_MODULES" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} MODULE_PATH="${ANOPEMOD}" >> ${WRKSRC}/config.cache
.endif
.if defined(WITH_MD5)
	@${ECHO_CMD} ENCRYPTION="ENCRYPT_MD5" >> ${WRKSRC}/config.cache
.endif
.if defined(WITH_THREAD)
	@${ECHO_CMD} THREAD="USE_THREADS" >> ${WRKSRC}/config.cache
.endif
.if defined(WITH_DREAM)
	@${ECHO_CMD} IRCTYPE=1 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_DREAMFORGE" >> ${WRKSRC}/config.cache
.elif defined(WITH_BAHAMUT)
	@${ECHO_CMD} IRCTYPE=2 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_BAHAMUT" >> ${WRKSRC}/config.cache
.elif defined(WITH_UNREAL)
	@${ECHO_CMD} IRCTYPE=3 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_DREAMFORGE" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF2="IRC_UNREAL" >> ${WRKSRC}/config.cache
.elif defined(WITH_ULT2)
	@${ECHO_CMD} IRCTYPE=4 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_DREAMFORGE" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF2="IRC_ULTIMATE" >> ${WRKSRC}/config.cache
.elif defined(WITH_ULT3)
	@${ECHO_CMD} IRCTYPE=5 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_BAHAMUT" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF2="IRC_ULTIMATE3" >> ${WRKSRC}/config.cache
.elif defined(WITH_HYB)
	@${ECHO_CMD} IRCTYPE=6 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_HYBRID" >> ${WRKSRC}/config.cache
.elif defined(WITH_VIA)
	@${ECHO_CMD} IRCTYPE=7 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_BAHAMUT" >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF2="IRC_VIAGRA" >> ${WRKSRC}/config.cache
.elif defined(WITH_PTL)
	@${ECHO_CMD} IRCTYPE=8 >> ${WRKSRC}/config.cache
	@${ECHO_CMD} IRCTYPE_DEF="IRC_PTLINK" >> ${WRKSRC}/config.cache
.endif
#}}}

pre-install:
	@${MKDIR} ${ANOPEBIN}
	@${MKDIR} ${ANOPEDAT}
	@${MKDIR} ${ANOPEMOD}

.include <bsd.port.post.mk>
