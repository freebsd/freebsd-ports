# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	namazu
PORTVERSION=	2.0.12
PORTREVISION=	2
CATEGORIES+=	databases www textproc
MASTER_SITES=	http://www.namazu.org/stable/
PKGNAMESUFFIX=	2

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-de.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Full-text search system intended for easy use

BUILD_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic
RUN_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv
#		xlHtml:${PORTSDIR}/textproc/xlhtml \
#		wvHtml:${PORTSDIR}/textproc/wv

PM_BASE=	${SITE_PERL}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5="${PERL}" \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE}

MAN1=		namazu.1 mknmz.1
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
	${RM} -rf ${PREFIX}/share/namazu/doc
.endif

.include <bsd.port.mk>
