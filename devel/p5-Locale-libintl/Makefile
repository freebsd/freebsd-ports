# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Locale-libintl
PORTVERSION=	1.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libintl-perl-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internationalization library for Perl

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv:translit localbase perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-patch-Makefile.PL
NLS_USES=		gettext

post-install-NLS-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Locale/gettext_xs/gettext_xs.so

.include <bsd.port.mk>
