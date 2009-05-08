# New ports collection makefile for:	libbobcat
# Date created:		March 4, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libbobcat
PORTVERSION=	2.02.02
CATEGORIES=	devel
MASTER_SITES=	SF/bobcat
DISTNAME=	bobcat_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Brokken's Own Base Classes And Templates

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		${LOCALBASE}/include/X11/Xlib.h:${PORTSDIR}/x11/libX11 \
		yodl>=2.0:${PORTSDIR}/textproc/yodl

MANCOMPRESSED=	yes
MAN1=		bobcatlcgen.1
MAN3=		a2x.3bobcat align.3bobcat arg.3bobcat argconfig.3bobcat \
		autoptr.3bobcat binarysearch.3bobcat cgi.3bobcat \
		clientsocket.3bobcat cmdfinder.3bobcat cmdfinderbase.3bobcat \
		configfile.3bobcat datetime.3bobcat errno.3bobcat \
		fnwrap1.3bobcat fnwrap1c.3bobcat fnwrap2.3bobcat \
		fnwrap2c.3bobcat foreach.3bobcat fork.3bobcat \
		gethostent.3bobcat glob.3bobcat hash.3bobcat hostent.3bobcat \
		hostname.3bobcat ifdstream.3bobcat ifdstreambuf.3bobcat \
		indent.3bobcat inetaddress.3bobcat iostream.3bobcat \
		iostreambuf.3bobcat irandstream.3bobcat lc.3bobcat level.3bobcat \
		lm.3bobcat localclientsocket.3bobcat localserversocket.3bobcat \
		localsocketbase.3bobcat log.3bobcat logbuffer.3bobcat \
		mailheaders.3bobcat manipulators.3bobcat milter.3bobcat \
		mlm.3bobcat msg.3bobcat multistreambuf.3bobcat ofdstream.3bobcat \
		ofdstreambuf.3bobcat ofilterstreambuf.3bobcat ofoldstream.3bobcat \
		ofoldstreambuf.3bobcat onekey.3bobcat pattern.3bobcat \
		pipe.3bobcat process.3bobcat randbuffer.3bobcat \
		redirector.3bobcat refcount.3bobcat repeat.3bobcat \
		selector.3bobcat serversocket.3bobcat socketbase.3bobcat \
		stat.3bobcat string.3bobcat syslogbuf.3bobcat \
		syslogstream.3bobcat table.3bobcat tablesupport.3bobcat \
		typetrait.3bobcat user.3bobcat x2a.3bobcat xpointer.3bobcat
MAN7=		bobcat.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/bobcat-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/doc/libbobcat2"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/libbobcat2-dev"|"/share/doc/${PORTNAME}-${PORTVERSION}/dev"| ; \
		s|"/share/man"|"/man"| ; \
		s|"-d"|"-Pp"| ; \
		s|#define MANHTML||' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"-Itmp -Wall -O3"|"-Itmp -I${LOCALBASE}/include -Wall ${CXXFLAGS}"|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|"cp -r |"cp -R |' \
		${WRKSRC}/icmake/install
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|#define DOCOTHER||' \
		${WRKSRC}/INSTALL.im
.endif

do-build:
	@cd ${WRKSRC} && ./build libraries all strip && ./build lcgen && ./build man

do-install:
	@cd ${WRKSRC} && ./build install

.include <bsd.port.mk>
