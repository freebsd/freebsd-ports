# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racket
PORTVERSION=	6.2
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment

LIB_DEPENDS=	libffi.so:devel/libffi	\
		libcairo.so:graphics/cairo	\
		libpng.so:graphics/png

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=		RACKET_PLACES
OPTIONS_DEFAULT=	RACKET_PLACES
RACKET_PLACES_DESC=	Enable Places
RACKET_PLACES_CONFIGURE_ENABLE=	places

CONFLICTS=	racket-minimal-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-lt --enable-shared --enable-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src
USES=		iconv jpeg libtool sqlite tar:tgz
USE_LDCONFIG=	yes
USE_GNOME=	pango

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CPPFLAGS+=	-DLONG64
.endif

post-install:
	${REINPLACE_CMD} -e "s@${STAGEDIR}@@" ${STAGEDIR}${PREFIX}/share/applications/*.desktop
	${RM} ${STAGEDIR}${PREFIX}/share/applications/*.bak

.include <bsd.port.mk>
