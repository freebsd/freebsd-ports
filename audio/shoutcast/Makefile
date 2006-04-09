# Ports collection Makefile for:	shoutcast
# Date created:				09 Oct 2005
# Whom:					Gabor Kovesdan
#
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	1.9.5
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://www.shoutcast.com/downloads/sc1-9-5/

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Nullsoft's streaming audio server (binary port)

ONLY_FOR_ARCHS=	i386 amd64 ia64
NO_BUILD=	YES
NO_PACKAGE=	Redistribution of the software isn\'t allowed

USE_RC_SUBR=	shoutcast.sh
PLIST_FILES=	sbin/sc_serv etc/shoutcast/sc_serv.conf.sample
PLIST_DIRS=	etc/shoutcast
PORTDOCS=	README.TXT

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
DISTNAME=	${PORTNAME}-1-9-5-freebsd5-elf
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif
.elif ${OSVERSION} >= 400000
DISTNAME=	${PORTNAME}-1-9-5-freebsd4-elf
.else
BROKEN=		unsupported FreeBSD version
.endif

post-patch:
	${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		-e 's|=sc_serv.log|=/var/log/sc_serv.log|' \
		-e 's|=sc_w3c.log|=/var/log/sc_w3c.log|' \
		-e 's|ScreenLog=1|ScreenLog=0|' \
		-e 's|RealTime=1|RealTime=0|' \
		-e 's|=sc_serv.ban|=${PREFIX}/etc/shoutcast/sc_serv.ban|' \
		-e 's|=sc_serv.rip|=${PREFIX}/etc/shoutcast/sc_serv.rip|' \
		${WRKSRC}/sc_serv.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/shoutcast
	${INSTALL_DATA} ${WRKSRC}/sc_serv.conf ${PREFIX}/etc/shoutcast/sc_serv.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
