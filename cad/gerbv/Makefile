# Created by: ijliao
# $FreeBSD$

PORTNAME=	gerbv
PORTVERSION=	2.6.1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gerber file viewer

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		desktop-file-utils gmake pathfix pkgconfig
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ENV=	ac_aux_dir="."
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^AM_NLS|#AM_NLS| ; \
		 s|^AM_GNU_GETTEXT|#AM_GNU_GETTEXT| ; \
		 /intl\/Makefile/d ; \
		 /po\/Makefile/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|=.*|= src man scheme|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^man_MANS/s|gerbv.ru.1|| ; \
		 s|^PO_|#PO_|' ${WRKSRC}/man/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|' \
		${WRKSRC}/src/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv.desktop \
		${STAGEDIR}${DESKTOPDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps)
.for i in 16 22 24 32 48
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} gerbv-${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gerbv.png)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.fig *.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/PNG-print
	(cd ${WRKSRC}/doc/PNG-print && ${INSTALL_DATA} *.jpg *.txt \
		${STAGEDIR}${DOCSDIR}/PNG-print)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/eagle
	(cd ${WRKSRC}/doc/eagle && ${INSTALL_DATA} *.pl *.txt \
		${STAGEDIR}${DOCSDIR}/eagle)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${FIND} . \
		! \( -name "*Makefile*" -or -name ".cvsignore" \) \
		| ${CPIO} --quiet -pdm -L -R ${SHAREOWN}:${SHAREGRP} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
