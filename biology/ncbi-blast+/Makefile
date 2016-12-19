# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	blast+
PORTVERSION=	2.5.0
CATEGORIES=	biology
MASTER_SITES=	http://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PORTVERSION}/ \
		http://acadix.biz/Ports/distfiles/
PKGNAMEPREFIX=	ncbi-
DISTNAME=	ncbi-blast-${PORTVERSION}+-src

MAINTAINER=	bacon4000@gmail.com
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/scripts/projects/blast/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils

WRKSRC=		${WRKDIR}/${DISTNAME}/c++

GNU_CONFIGURE=	yes
USES=		gmake shebangfix perl5 python
SHEBANG_FILES=	src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/winmasker/windowmasker_2.2.22_adapter.py

# Requires openmp
USE_GCC=	yes
USE_LDCONFIG=	yes

# The test for amq can hang, but amq is not needed so just avoid the test
CONFIGURE_ENV=	ncbi_cv_prog_amq_w=no

# configure chooses /usr/local/bin/ar with no flags
# FreeBSD boost port flagged by configure as untested version
CONFIGURE_ARGS+=AR="ar cr" --without-boost

# Fix "undefined _ThreadRuneLocale" error on 10.0
# Fix unknown options in configure
# Add staging support to configure-generated Makefile
post-patch:
	${REINPLACE_CMD} \
		-e 's|-D_THREAD_SAFE|-D_THREAD_SAFE -D__RUNETYPE_INTERNAL|' \
		-e '/--infodir=DIR/d' \
		-e '/--mandir=DIR/d' \
		${WRKSRC}/src/build-system/configure
	${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}@prefix@|g' \
		${WRKSRC}/src/build-system/Makefile.in.top

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
