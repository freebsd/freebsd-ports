# New ports collection makefile for:	namazu2
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ja-namazu2
PORTVERSION=	2.0.3
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.namazu.org/stable/
DISTNAME=	namazu-${PORTVERSION}

MAINTAINER=	knu@idaemons.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${PM_BASE}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi \
		${PM_BASE}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf
RUN_DEPENDS=	${PM_BASE}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${PM_BASE}/${PERL_ARCH}/Text/Kakasi.pm:${PORTSDIR}/japanese/p5-Text-Kakasi \
		${PM_BASE}/${PERL_ARCH}/NKF.pm:${PORTSDIR}/japanese/p5-nkf \
		xlHtml:${PORTSDIR}/textproc/xlhtml

PM_BASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

USE_PERL5=	yes
GNU_CONFIGURE=	yes

MAN1=		namazu.1 mknmz.1

post-install:
	${LN} -sf ${PREFIX}/lib/libnmz.so.3 ${PREFIX}/lib/libnmz.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
