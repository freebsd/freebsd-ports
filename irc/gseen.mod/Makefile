# Ports collection makefile for:  gseen.mod
# Date created:			  28 Mai 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	gseen.mod
PORTVERSION=	1.1.1.p3
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	http://www.kreativrauschen.de/gseen.mod/
DISTNAME=	${PORTNAME}.${PORTVERSION:S/p/dev/}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	A seen-module for the eggdrop IRC bot

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/irc/eggdrop:extract
BUILD_DEPENDS=	eggdrop:${PORTSDIR}/irc/eggdrop
RUN_DEPENDS=	eggdrop:${PORTSDIR}/irc/eggdrop

USE_TCL=	85+

WRKSRC=		${WRKDIR}/eggdrop

CONFIGURE_ARGS=	--with-tcllib=${LOCALBASE}/lib/libtcl${TCL_VER:S/.//}.so \
		--with-tclinc=${TCL_INCLUDEDIR}/tcl.h

MAKE_JOBS_UNSAFE=	yes
GNU_CONGFIGURE=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} -R $$(${MAKE} -C ${PORTSDIR}/irc/eggdrop -V WRKSRC) ${WRKSRC}
	cd ${WRKSRC}/src/mod && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

post-extract:
	${REINPLACE_CMD} -e 's|"-g -O2"|"${CFLAGS}"|' \
		-e 's|"-g"|"${CFLAGS}"|' \
		-e 's|"-O2"|"${CFLAGS}"|' \
		${WRKSRC}/configure

pre-build:
	@${ECHO_CMD} gseen.mod >> ${WRKSRC}/.modules
	@${ECHO_CMD} gseen.mod >> ${WRKSRC}/.known_modules
	@cd ${WRKSRC} && ./configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gseen.so ${PREFIX}/lib/eggdrop
	@${INSTALL_DATA} ${WRKSRC}/src/mod/gseen.mod/*lang ${PREFIX}/share/eggdrop/language
	@${INSTALL_DATA} ${WRKSRC}/src/mod/gseen.mod/gseen.conf ${PREFIX}/etc
	@${ECHO_MSG} "Please add the line"
	@${ECHO_MSG} "source ${PREFIX}/etc/gseen.conf"
	@${ECHO_MSG} "at the end of your eggdrop config file"
	@${ECHO_MSG} "and .rehash your bot"

.include <bsd.port.mk>
