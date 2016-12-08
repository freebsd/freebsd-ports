# Created by: ijliao
# $FreeBSD$

PORTNAME=	gerbv
PORTVERSION=	2.6.1
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gerber file viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf desktop-file-utils gmake libtool localbase pathfix pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_aux_dir="."
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS EXAMPLES

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.fig *.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/PNG-print
	(cd ${WRKSRC}/doc/PNG-print && ${INSTALL_DATA} *.jpg *.txt \
		${STAGEDIR}${DOCSDIR}/PNG-print)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/eagle
	(cd ${WRKSRC}/doc/eagle && ${INSTALL_DATA} *.pl *.txt \
		${STAGEDIR}${DOCSDIR}/eagle)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/example && ${FIND} . \
		! \( -name "*Makefile*" -or -name ".cvsignore" \) \
		| ${CPIO} --quiet -pdm -L -R ${SHAREOWN}:${SHAREGRP} \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
