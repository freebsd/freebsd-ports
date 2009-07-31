# ports collection makefile for:	cwirc
# Date created:		9 April 2008
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	cwirc
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	irc comms hamradio
MASTER_SITES=	http://users.skynet.be/ppc/cwirc/download/ \
		http://www.db.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	X-Chat morse plugin

BUILD_DEPENDS=	xchat:${PORTSDIR}/irc/xchat

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
	${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in COPYING LISEZMOI README RELEASE_NOTES
	@${INSTALL_DATA}  ${WRKSRC}/$f ${DOCSDIR}
.endfor
	${MKDIR} ${DOCSDIR}/schematics
.for f in cw_oscillator.jpg rs232_key_connection.jpg
	@${INSTALL_DATA} ${WRKSRC}/schematics/$f ${DOCSDIR}/schematics
.endfor
	@${ECHO} ""
	@${ECHO} "cwirc docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
