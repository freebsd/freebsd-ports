PORTNAME=	xnec2c
PORTVERSION=	4.4.16
DISTVERSIONPREFIX=	v
CATEGORIES=	comms hamradio
MASTER_SITES=	https://www.xnec2c.org/releases/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio
WWW=		https://www.xnec2c.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf desktop-file-utils gettext gmake gnome pkgconfig \
		shared-mime-info

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV+=			LIBS=-lexecinfo
USE_GNOME=			cairo gdkpixbuf2 glib20 gtk30 intltool

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in NEC2-bug.txt nec2c.txt xnec2c.html NearFieldCalcs.txt
	${INSTALL_DATA} ${WRKSRC}/doc/$f ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
.for f in currents.png freq_plots.png radiation.png web-heading.xcf \
	excitation.png nec2_edit.png web-heading.png wire.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/$f ${STAGEDIR}${DOCSDIR}/images
.endfor

.include <bsd.port.mk>
