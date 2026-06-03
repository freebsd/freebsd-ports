PORTNAME=	xnec2c
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.18
CATEGORIES=	comms hamradio
MASTER_SITES=	https://www.xnec2c.org/releases/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio
WWW=		https://www.xnec2c.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf desktop-file-utils gettext gmake gnome pkgconfig \
		shared-mime-info
USE_GNOME=	cairo gdkpixbuf glib20 gtk30 intltool

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS=-lexecinfo

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

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

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DATADIR}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${RM} -r ${STAGEDIR}${DATADIR} # Remove pre-installed examples

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${DATADIR} # Remove pre-installed examples

.include <bsd.port.mk>
