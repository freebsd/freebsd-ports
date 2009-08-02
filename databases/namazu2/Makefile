# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	namazu
PORTVERSION=	2.0.19
CATEGORIES+=	databases www textproc
MASTER_SITES=	http://www.namazu.org/stable/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-text search system intended for easy use

BUILD_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic
RUN_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic

PM_BASE=	${SITE_PERL}

USE_PERL5=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-perl5="${PERL}" \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}
USE_LDCONFIG=	yes

MAN1=		namazu.1 mknmz.1

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.css ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${DOCSDIR}/en
	@${MKDIR} ${DOCSDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/doc/ja/*.html ${DOCSDIR}/ja
.endif

.include <bsd.port.mk>
