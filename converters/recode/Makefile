# New ports collection makefile for:	recode
# Date created:		14 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	recode
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	recode

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_PERL5=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--without-included-gettext
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		recode.1

post-extract: copy-po-files remove-info-files

copy-po-files:
	@${CP} ${FILESDIR}/ru.po ${WRKSRC}/i18n

remove-info-files:
	@${RM} -f ${WRKSRC}/doc/${PORTNAME}.info*

post-patch: patch-po-files patch-makeinfo

patch-po-files:
	@${PERL} -pi -e '\
		if (/Project-Id-Version/) { \
			s/3\.[45](r|\.[0-9])?/3.6/; \
			s/: (Free )?recode/: GNU recode/; \
		} \
	' ${WRKSRC}/i18n/*.po

patch-makeinfo:
	@${REINPLACE_CMD} -e 's|\@MAKEINFO\@|\@MAKEINFO\@ --no-split|g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
