# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	namazu
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	japanese databases www textproc
MASTER_SITES=	http://www.namazu.org/stable/
PKGNAMESUFFIX=	2

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${PM_BASE}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf \
		${DEPEND_WAKATI}
RUN_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${PM_BASE}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf \
		${DEPEND_WAKATI}
#		xlHtml:${PORTSDIR}/textproc/xlhtml \
#		wvHtml:${PORTSDIR}/textproc/wv

PM_BASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		namazu.1 mknmz.1
INSTALLS_SHLIB=	yes

.if defined(WITH_CHASEN)
DEPEND_WAKATI=	${PM_BASE}/${PERL_ARCH}/Text/ChaSen.pm:${PORTSDIR}/japanese/p5-Text-ChaSen
.else
DEPEND_WAKATI=	${PM_BASE}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi
.endif

post-configure:
	${PERL} -i~ -pe 's,^(LIBS *= *)(.*),$$1 -L${LOCALBASE}/lib -lintl $$2\n,' ${WRKSRC}/nmz/Makefile

post-install:
.if defined(NOPORTDOCS)
	${RM} -rf ${PREFIX}/share/namazu/doc
.endif

.include <bsd.port.mk>
