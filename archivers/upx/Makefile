# New ports collection makefile for:	upx
# Date created:				17 Feb 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	upx
PORTVERSION=	1.25
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	upx/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	The Ultimate Packer for eXecutables

LIB_DEPENDS=	ucl.1:${PORTSDIR}/archivers/ucl

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
MAKE_ENV=	UCLDIR=${LOCALBASE} target=freebsd

PORTDOCS=	BUGS COPYING LICENSE NEWS README THANKS
MAN1=		upx.1
PLIST_FILES=	bin/upx

post-patch:
	@${CP} ${FILESDIR}/l_b_n2?.h ${WRKSRC}/stub

post-build:
	@cd ${WRKSRC}/../doc && ${GMAKE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/upx ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/../doc/upx.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/../$$i ${DOCSDIR}; \
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
