# New ports collection makefile for:	uudeview
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $FreeBSD$
#

PORTNAME=	uudeview
PORTVERSION=	0.5.20
CATEGORIES=	converters
MASTER_SITES=	http://www.fpx.de/fp/Software/UUDeview/download/

MAINTAINER=	hoek@FreeBSD.org
COMMENT=	A program for uu/xx/Base64/BinHex/yEnc de-/encoding

LIB_DEPENDS=	uu.3:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-tcl

.include <bsd.port.pre.mk>

# Try and catch some of the different places that inn and cnews put inews
.if exists(${PREFIX}/bin/inews)
# cnews
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/bin/inews
.else
# inn by default
CONFIGURE_ARGS+=	--enable-inews=${PREFIX}/news/lib/inews
.endif

MAN1=		uudeview.1 uuenview.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/uudeview
	@${STRIP_CMD} ${PREFIX}/bin/uuenview
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/HISTORY ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/porting.notes ${DOCSDIR}
.else
	@${ECHO_MSG} "===>  Not installing available documents"
.endif

.include <bsd.port.post.mk>
