# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	recode
PORTVERSION=	3.6
PORTREVISION=	9
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	recode

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Converts files between character sets and usages

USES=		gettext iconv perl5
USE_AUTOTOOLS=	libtool
USE_PERL5=	patch run build
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--without-included-gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CFLAGS+=	-fPIC

INFO=		recode

post-extract:
	@${CP} ${FILESDIR}/ru.po ${WRKSRC}/i18n
	@${RM} -f ${WRKSRC}/doc/${PORTNAME}.info*

post-patch:
	@${PERL} -pi -e '\
		if (/Project-Id-Version/) { \
			s/3\.[45](r|\.[0-9])?/3.6/; \
			s/: (Free )?recode/: GNU recode/; \
		} \
	' ${WRKSRC}/i18n/*.po

.include <bsd.port.mk>
