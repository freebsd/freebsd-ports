# New ports collection makefile for:	ezbounce
# Date created:	 	19 February 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezbounce
PORTVERSION=	1.02
CATEGORIES=	irc
MASTER_SITES=  	http://druglord.freelsd.org/ezbounce/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE= 	yes

MAN1=		ezbounce.1

.if !defined(WITH_MDIDENTD)
ALL_TARGET=	ezbounce_src
PLIST_SUB+=	MDIDENTD="@comment "
.else
PLIST_SUB+=	MDIDENTD=""
.endif

post-patch:
	@${SED} -e "s:/path/to:${PREFIX}/sbin:" ${WRKSRC}/sample.conf > \
		${WRKSRC}/ezb.conf.default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezb.conf.default ${PREFIX}/etc
	${INSTALL_MAN}	${WRKSRC}/misc/ezbounce.1 ${PREFIX}/man/man1

.if defined(WITH_MDIDENTD)
	${INSTALL_PROGRAM} ${WRKSRC}/mdidentd/mdidentd ${PREFIX}/sbin
.endif

	@if [ ! -f ${PREFIX}/etc/ezb.conf ]; then \
		${INSTALL_DATA} \
		${WRKSRC}/ezb.conf.default ${PREFIX}/etc/ezb.conf; \
	fi

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/worklog ${PREFIX}/share/doc/ezbounce

.if defined(WITH_MDIDENTD)
	${INSTALL_DATA} ${WRKSRC}/mdidentd/README \
		${PREFIX}/share/doc/ezbounce/mdidentd.README
.endif

.endif
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
