# New ports collection makefile for:	upx
# Date created:				17 Feb 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	upx
PORTVERSION=	3.01
CATEGORIES=	archivers
MASTER_SITES=	http://upx.sourceforge.net/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The Ultimate Packer for eXecutables

LIB_DEPENDS=	ucl.1:${PORTSDIR}/archivers/ucl

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ENV=	UPX_UCLDIR=${LOCALBASE} target=freebsd

PORTDOCS=	BUGS COPYING LICENSE NEWS README THANKS
MAN1=		upx.1
PLIST_FILES=	bin/upx

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${PREFIX}/bin/upx
	@${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
