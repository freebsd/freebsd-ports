# New ports collection makefile for:	gal
# Date created:        30 October 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

# This port does not work with another version of master port.
CATEGORIES=	japanese x11-toolkits gnome

MASTERDIR=	${.CURDIR}/../../x11-toolkits/gal

MAINTAINER=	ports@FreeBSD.org

USE_PERL5_BUILD=yes

post-patch:
	perl -pi -e  's/gdk_font_load(\s)\(.*\)/gdk_fontset_load$$1\("-misc-fixed-medium-r-normal--14-*-*-*-*-*-*-*"\)/' \
		`${FIND} ${WRKSRC} -name "*.c" -print`

.include "${MASTERDIR}/Makefile"
