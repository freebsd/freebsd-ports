PORTNAME=	solfege
DISTVERSION=	3.23.5pre2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://git.savannah.gnu.org/cgit/${PORTNAME}.git/snapshot/
PKGNAMESUFFIX=	-nosound

MAINTAINER=	m.ne@gmx.net
COMMENT=	Free ear training software
WWW=		https://www.gnu.org/software/solfege/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl \
		git>0:devel/git \
		txt2man:textproc/txt2man
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		autoreconf gettext gmake gnome makeinfo pkgconfig \
		python shebangfix
USE_GNOME=	pygobject3

SHEBANG_FILES=	exercises/standard/lesson-files/bin/csound-play-harmonic-interval.sh

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=			--disable-oss-sound \
				--enable-docbook-stylesheet=${STYLESHEET}
CONFIGURE_ENV=			ac_cv_path_XML2PO=""

MAKE_ARGS=	nopycompile=YES \
		skipmanual=yes

NO_ARCH=	yes

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

STYLESHEET=	${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl

post-patch:
	@${REINPLACE_CMD} -e \
		's|cp --parents|${PAX} -rw|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|type=sequencer-device|type=fake-synth| ; \
		 s|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/default.config

post-install:
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${DATADIR_REL})

.include <bsd.port.mk>
