# $FreeBSD$

PORTNAME=	libbobcat
PORTVERSION=	3.11.01
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/bobcat/bobcat/${PORTVERSION}
DISTNAME=	bobcat_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Brokken's Own Base Classes And Templates

LICENSE=	GPLv3

BUILD_DEPENDS=	icmake:${PORTSDIR}/devel/icmake \
		yodl>=3.0:${PORTSDIR}/textproc/yodl

USE_XORG=	x11

MANCOMPRESSED=	yes
MAN3=		a2x.3bobcat align.3bobcat arg.3bobcat argconfig.3bobcat \
		bigint.3bobcat binarysearch.3bobcat \
		binops.3bobcat cgi.3bobcat cidr.3bobcat clientsocket.3bobcat \
		cmdfinder.3bobcat cmdfinderbase.3bobcat configfile.3bobcat \
		datetime.3bobcat decryptbuf.3bobcat digestbuf.3bobcat \
		encryptbuf.3bobcat errno.3bobcat fork.3bobcat fswap.3bobcat \
		gethostent.3bobcat glob.3bobcat hash.3bobcat hmacbuf.3bobcat \
		hostent.3bobcat hostname.3bobcat ifdstream.3bobcat \
		ifdstreambuf.3bobcat indent.3bobcat inetaddress.3bobcat \
		iostream.3bobcat iostreambuf.3bobcat irandstream.3bobcat \
		level.3bobcat lm.3bobcat localclientsocket.3bobcat \
		localserversocket.3bobcat localsocketbase.3bobcat log.3bobcat \
		logbuffer.3bobcat mailheaders.3bobcat manipulators.3bobcat \
		mbuf.3bobcat milter.3bobcat mlm.3bobcat \
		mstream.3bobcat multistreambuf.3bobcat ofdstream.3bobcat \
		ofdstreambuf.3bobcat ofilterstreambuf.3bobcat \
		ofoldstream.3bobcat ofoldstreambuf.3bobcat \
		ohexstreambuf.3bobcat onekey.3bobcat pattern.3bobcat \
		pipe.3bobcat process.3bobcat ptriter.3bobcat randbuffer.3bobcat \
		ranger.3bobcat readlinebuf.3bobcat readlinehistory.3bobcat \
		readlinestream.3bobcat redirector.3bobcat \
		repeat.3bobcat selector.3bobcat serversocket.3bobcat \
		signal.3bobcat socketbase.3bobcat stat.3bobcat string.3bobcat \
		stringline.3bobcat syslogbuf.3bobcat syslogstream.3bobcat \
		table.3bobcat tablebuf.3bobcat tablelines.3bobcat \
		tablesupport.3bobcat tempstream.3bobcat typetrait.3bobcat \
		user.3bobcat x2a.3bobcat xpointer.3bobcat
MAN7=		bobcat.7

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

USE_GCC=	4.6
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/bobcat-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|"/usr"|"${PREFIX}"| ; \
		s|"/share/doc/libbobcat3"|"/share/doc/${PORTNAME}-${PORTVERSION}"| ; \
		s|"/share/doc/libbobcat3-dev"|"/share/doc/${PORTNAME}-${PORTVERSION}/dev"| ; \
		s|"/share/man"|"/man"| ; \
		s|"-d"|"-Pp"| ; \
		s|#define MANHTML|| ; \
		s|g++|g++46| ; \
		s|gcc|gcc46|' \
		${WRKSRC}/INSTALL.im
	@${REINPLACE_CMD} -e 's|#!/usr/bin/icmake|#!${LOCALBASE}/bin/icmake| ; \
		s|"-isystem tmp -Wall -O3"|"-isystem tmp ${LOCALBASE}/include -Wall ${CXXFLAGS}"|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e 's|"cp -r |"cp -R |' \
		${WRKSRC}/icmake/install
	@${REINPLACE_CMD} -e 's|-lssl|-lssl -L${LOCALBASE}/lib| ; \
		s|-lX11|-lX11 -L${LOCALBASE}/lib| ; \
		s|-lmilter|-lmilter -lpthread|' \
		${WRKSRC}/icmake/special
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|#define DOCOTHER||' \
		${WRKSRC}/INSTALL.im
.endif

do-build:
	@cd ${WRKSRC} && ./build libraries all strip && ./build man

do-install:
	@cd ${WRKSRC} && ./build install

.include <bsd.port.mk>
