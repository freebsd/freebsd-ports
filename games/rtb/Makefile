# Created by: Dishanker Rajakulendren <draj@oceanfree.net>
# $FreeBSD$

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.8
DISTVERSIONSUFFIX=	-Ext
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}-1.0.x/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot programming game for UNIX

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USES=		gettext gmake perl5 pkgconfig
USE_GNOME=	gtk20
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rtb-dir=${PREFIX}/lib/${PORTNAME}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="${PORTNAME}" "" "" "${PORTNAME:L}" "" ""

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
