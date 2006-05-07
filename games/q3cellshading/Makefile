# New ports collection makefile for:	quake3
# Date created:				23 August 2005
# Whom:					pypt
#
# $FreeBSD$
#

PORTNAME=	quake3
PORTVERSION=	1.32b
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|source/|} \
		http://www.proarena.com/p/ftpx/x8524/quake_3_arena/ \
		http://www.planetgargoyle.com/ \
		http://www.teamdarkside.net/ \
		http://0day.icculus.org/mirrors/quake3/ \
		http://www.olpainless.net/files/
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	Quake III Arena -- first person shooter (native build)

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_ZIP=	yes
USE_CRLF=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GL=		yes
USE_GCC=	3.2+

PLIST_FILES=	bin/q3ded bin/quake3

.include <bsd.port.pre.mk>

# Anyone to play with this on !i386
.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386 (feel free to submit fixes)"
.endif

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%Q3DIR%%|"${Q3DIR}"|' \
		${WRKSRC}/code/unix/unix_shared.c
	@${REINPLACE_CMD} -e 's|botlib.log|/dev/null|' ${WRKSRC}/code/botlib/be_interface.c

pre-build:
	${MKDIR} ${WRKSRC}/lcc/build

do-build:
	cd ${WRKSRC}/code && ${MAKE_ENV} ${PERL} unix/cons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/code/install/linuxq3ded \
		${PREFIX}/bin/q3ded
	${INSTALL_PROGRAM} ${WRKSRC}/code/install/linuxquake3 \
		${PREFIX}/bin/quake3

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
