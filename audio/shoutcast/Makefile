# Ports collection Makefile for:	shoutcast
# Date created:				09 Oct 2005
# Whom:					Gabor Kovesdan
#
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	1.9.5
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://www.shoutcast.com/downloads/sc1-9-5/

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Nullsoft's streaming audio server (binary port)

ONLY_FOR_ARCHS=	i386
NO_BUILD=	YES
NO_PACKAGE=	Redistribution of the software isn't allowed

USE_RC_SUBR=	shoutcast.sh
PLIST_FILES=	sbin/sc_serv etc/shoutcast/sc_serv.conf
PLIST_DIRS=	etc/shoutcast
PORTDOCS=	README.TXT
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
DISTNAME=	${PORTNAME}-1-9-5-freebsd5-elf
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif
.elif ${OSVERSION} >= 400000
DISTNAME=	${PORTNAME}-1-9-5-freebsd4-elf
.else
BROKEN=		"unsupported FreeBSD version"
.endif

post-patch:
	@${CAT} ${PKGDIR}/pkg-message | ${SED} 's|%%PREFIX%%|${PREFIX}|' > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/shoutcast
	${INSTALL_DATA} ${WRKSRC}/sc_serv.conf ${PREFIX}/etc/shoutcast
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
