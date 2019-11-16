# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gsuica
PORTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	japanese ruby
MASTER_SITES=	http://hito.music.coocan.jp/pasori/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GNOME SUICA Viewer

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-gtk2>0:x11-toolkits/rubygem-gtk2 \
		rubygem-gio2>=3.1.0:devel/rubygem-gio2 \
		${RUBY_SITEARCHLIBDIR}/pasori.so:devel/libpafe-ruby

USE_RUBY=	yes
USES=		shebangfix
SHEBANG_FILES=	${PORTNAME}
ruby_OLD_CMD=	/usr/bin/ruby1.9.3

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	.
NO_WRKSUBDIR=		yes
NO_ARCH=		yes
NO_BUILD=		yes

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/Gdk::Atom.new(0)/Gdk::Selection::CLIPBOARD/g' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

# Fetch station code database
station-code-fetch:
	@(cd ${WRKDIR}; \
	  ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		-o StationCode.xls \
		http://www.denno.net/SFCardFan/sendexcel.php; \
		${FETCH_AFTER_ARGS} \
	  ${SETENV} ${FETCH_ENV} ${FETCH_CMD} ${FETCH_BEFORE_ARGS} \
		${MASTER_SITES}station_code_conv.sh ${FETCH_AFTER_ARGS})

# Install station code database into ~/.gsuica/station_code
# BUILD_DEPENDS+=	nkf:japanese/nkf
# BUILD_DEPENDS+=	xlhtml:textproc/xlhtml
station-code-install:
	@(cd ${WRKDIR}; ${SH} station_code_conv.sh StationCode.xls)

.include <bsd.port.mk>
