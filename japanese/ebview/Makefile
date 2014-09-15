# $FreeBSD$

PORTNAME=	ebview
PORTVERSION=	0.2.1
PORTREVISION=	16
CATEGORIES=	japanese
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libeb.so:${PORTSDIR}/japanese/eb

OPTIONS_DEFINE=	DOCS

CONFLICTS=	ja-ebview-gtk2-[0-9]*

USES=		gettext gmake
USE_GNOME=	imlib
USE_AUTOTOOLS=	autoconf
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|// .*||' ${WRKSRC}/src/dictheading.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
