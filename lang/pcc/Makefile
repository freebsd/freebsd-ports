# Created by: David O'Brien <obrien@NUXI.org>
# $FreeBSD$

PORTNAME=	pcc
PORTVERSION=	1.0.0
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/ \
		ftp://226.net120.skekraft.net/pcc-releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	joel@FreeBSD.org
COMMENT=	Portable C Compiler

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=${YACC}

PLIST_FILES=	bin/pcc libexec/ccom libexec/cpp \
		man/man1/ccom.1.gz man/man1/cpp.1.gz \
		man/man1/pcc.1.gz

# Fix -jX builds: use -C switch instead of cd'ing and add missing dependency

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E \
	's/cd (.+)(;| &&) (\$$[{(]MAKE[})][^$$]*)( \$$\(MFLAGS\))?/\3 -C \1/'
	@${ECHO_CMD} 'builtins.o: pass1.h' >> ${WRKSRC}/cc/ccom/Makefile.in

pre-configure:
	${MKDIR} ${WRKSRC}/os/freebsd
	${CP} ${FILESDIR}/*.h ${WRKSRC}/os/freebsd
	${REINPLACE_CMD} -e "s,%%OSVERMAJOR%%,${OSREL:R}," \
		${WRKSRC}/os/freebsd/ccconfig.h

.include <bsd.port.mk>
