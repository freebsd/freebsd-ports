# Ports collection Makefile for:	shoutcast
# Date created:				09 Oct 2005
# Whom:					Gabor Kovesdan
#
# $FreeBSD$

PORTNAME=	shoutcast
PORTVERSION=	1.9.7
PORTREVISION=	1
CATEGORIES=	audio net
MASTER_SITES=	http://www.shoutcast.com/downloads/sc1-9-7/
DISTNAME=	${PORTNAME}-1-9-7-freebsd5-elf

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Nullsoft's streaming audio server (binary port)

IA32_BINARY_PORT=	YES
NO_BUILD=	YES
RESTRICTED=	Redistribution of the software is not allowed

CONFLICTS=	linux-shoutcast-[0-9]*

USE_RC_SUBR=	shoutcast.sh
PORTDOCS=	README.TXT
WRKSRC=		${WRKDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//' \
		-e 's|=sc_serv.log|=/var/log/sc_serv.log|' \
		-e 's|=sc_w3c.log|=/var/log/sc_w3c.log|' \
		-e 's|ScreenLog=1|ScreenLog=0|' \
		-e 's|RealTime=1|RealTime=0|' \
		-e 's|=sc_serv.ban|=${PREFIX}/etc/shoutcast/sc_serv.ban|' \
		-e 's|=sc_serv.rip|=${PREFIX}/etc/shoutcast/sc_serv.rip|' \
		${WRKSRC}/sc_serv.conf

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/sc_serv ${PREFIX}/sbin
	@${MKDIR} ${PREFIX}/etc/shoutcast
	@${INSTALL_DATA} ${WRKSRC}/sc_serv.conf ${PREFIX}/etc/shoutcast/sc_serv.conf.sample
	@[ -f ${PREFIX}/etc/shoutcast/sc_serv.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/sc_serv.conf ${PREFIX}/etc/shoutcast/sc_serv.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
