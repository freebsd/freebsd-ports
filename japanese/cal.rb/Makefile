# New ports collection makefile for:   cal.rb
# Date created:                3 October 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	cal.rb
PORTVERSION=	0.2
CATEGORIES=	japanese deskutils
MASTER_SITES=	http://aglaia.c.u-tokyo.ac.jp/~yamamoto/Script/Calendar/
DISTFILES=	cal.rb Calendar.rb era_name
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	fuyuki@hadaly.org

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	${WRKSRC}/cal.rb
NO_BUILD=	yes

LIBDIR=		${PREFIX}/libdata/cal

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor

post-patch:
	${RUBY} -i -pe 'sub "chdir(.*)", %q{chdir("${LIBDIR}")}' ${WRKSRC}/cal.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cal.rb ${PREFIX}/bin
	${MKDIR} ${LIBDIR}
.for i in Calendar.rb era_name
	${INSTALL_DATA} ${WRKSRC}/${i} ${LIBDIR}
.endfor

.include <bsd.port.mk>
