# New ports collection makefile for:   cal.rb
# Date created:                3 October 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	cal.rb
PORTVERSION=	1.17
CATEGORIES=	japanese deskutils
MASTER_SITES=	http://aglaia.c.u-tokyo.ac.jp/~yamamoto/Script/Calendar/
DISTFILES=	cal.rb Calendar.rb era_name
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays a Japanese calendar

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	${WRKSRC}/cal.rb
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	${RUBY} -i -pe 'sub "./era_name", "${DATADIR}/era_name"' \
		${WRKSRC}/Calendar.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cal.rb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Calendar.rb ${RUBY_SITELIBDIR}
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/era_name ${DATADIR}

.include <bsd.port.mk>
