# ex:ts=8
# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	2.03
CATEGORIES=	ftp
MASTER_SITES=	http://www.krasu.ru/soft/chuchelo/files/ \
		ftp://ftp.chg.ru/pub/X11/applications/Xdownloader/ \
		http://www.scutty.co.uk/downloader/software/ \
		ftp://ftp.uni-klu.ac.at/pub/linux/internet/downloader/
DISTNAME=	d4x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 esound
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-release

MAN1=		nt.1

DOCSDIR=	${PREFIX}/share/doc/d4x
PORTDOCS=	FAQ FAQ.de FAQ.es FAQ.fr FAQ.gr INSTALL INSTALL.de \
		INSTALL.es INSTALL.fr INSTALL.gr INSTALL.he INSTALL.pl \
		INSTALL.pt_BR LICENSE NAMES THANKS TROUBLES

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS="-O."|CXXFLAGS=\$$CXXFLAGS|g ; \
		 s|OS_CXXFLAGS="-pthread"|OS_CXXFLAGS="${PTHREAD_CFLAGS}"|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| DOC||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-not|\\!|g' ${WRKSRC}/share/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/DOC/nt.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/DOC/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
