# New ports collection makefile for:	uudeview
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	uudeview
PORTVERSION=	0.5.18
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	hoek@FreeBSD.org

LIB_DEPENDS=	uu.2:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-inews=${PREFIX}/news/lib/inews \
		--disable-tcl

MAN1=		uudeview.1 uuenview.1

post-install:
	@/usr/bin/strip ${PREFIX}/bin/uudeview
	@/usr/bin/strip ${PREFIX}/bin/uuenview
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/HISTORY ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/porting.notes ${DOCSDIR}
.else
	@${ECHO_MSG} "===>  Not installing available documents"
.endif

.include <bsd.port.mk>
