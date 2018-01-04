# Created by: Dishanker Rajakulendren <draj@oceanfree.net>
# $FreeBSD$

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.8
DISTVERSIONSUFFIX=	-Ext
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}-1.0.x/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		gettext gmake perl5 pkgconfig python:2.7 tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rtb-dir=${PREFIX}/lib/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="${PORTNAME}" "" "" "${PORTNAME:tl}" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
.for i in configure
	@${REINPLACE_CMD} -e 's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\$${top_builddir}/intl/libintl.a|-lintl|g ; \
		 /^DOCS_DIR/s|=.*|=$${prefix}/share/doc/${PORTNAME}| ; \
		 /test/s| == | = |g' ${WRKSRC}/${i}
.endfor
.for i in Documentation/Makefile.in
	@${REINPLACE_CMD} -e '/COPYING/d' ${WRKSRC}/${i}
.endfor
.for i in team-framework/createrobot.sh \
	team-framework/createrobotconf.sh
	@${REINPLACE_CMD} -e 's| sed| gsed|g' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
