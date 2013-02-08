# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	soundtouch
PORTVERSION=	1.7.1
CATEGORIES=	audio
MASTER_SITES=	http://www.surina.net/soundtouch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source audio processing library

LICENSE=	LGPL21

OPTIONS_DEFINE=	INTEGER_SAMPLES DOCS
INTEGER_SAMPLES_DESC=	Use integer sample format

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
ACLOCAL_ARGS=	-I config/m4
AUTOMAKE_ARGS=	--add-missing --copy --foreign
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINTEGER_SAMPLES}
CONFIGURE_ARGS+=	--enable-integer-samples
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^pkgdoc_DATA|#pkgdoc_DATA| ; \
		 s|$$(libdir)/pkgconfig|$$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am
	@${FIND} ${WRKSRC}/source -name "Makefile.am" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|-O[0-9]|| ; \
		 s|-msse||'

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
