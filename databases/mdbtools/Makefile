# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	0.5
PORTREVISION=	14
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

# To build man-pages
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

USES=		bison pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	glib20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO
MAN1=		mdb-ver.1 mdb-tables.1 mdb-schema.1 mdb-sql.1 mdb-export.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_XORG=	x11
USES+=		pathfix
USE_GNOME+=	gnomeprefix libgnomeui
PKGNAMESUFFIX=	-gnome
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(srcdir)/$$<|$$(srcdir)/$$>|g' \
		${WRKSRC}/doc/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f}  ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
