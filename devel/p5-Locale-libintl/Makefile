# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Locale-libintl
PORTVERSION=	1.23
PORTREVISION=	2
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	libintl-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Internationalization library for Perl

LICENSE=	LGPL21

USES=		gettext perl5 shebangfix
SHEBANG_FILES=	lib/Locale/Messages.pm \
		lib/Locale/TextDomain.pm \
		lib/Locale/gettext_dumb.pm \
		lib/Locale/gettext_pp.pm \
		lib/Locale/gettext_xs.pod
SHEBANG_LANG=	false
false_OLD_CMD=	/bin/false
false_CMD=	/usr/bin/false
USE_PERL5=	configure

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Locale/gettext_xs/gettext_xs.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Locale/gettext_xs/gettext_xs.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Locale/gettext_xs/gettext_xs.so

.include <bsd.port.mk>
