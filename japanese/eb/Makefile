# New ports collection makefile for:	eb
# Date created:			20 Jan 1999
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	eb
PORTVERSION=	3.3.4
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/net/ndtp/eb/
DISTFILES=	${EBFILES} \
		${LISTFILES} \
		${APPENDIXFILES}
EXTRACT_ONLY=	${EBFILES}

PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	${DISTNAME}+.diff ${DISTNAME}+2.diff

MAINTAINER=	takamune2004@yahoo.co.jp
COMMENT=	C library for accessing EB, EBG, EBXA and EPWING CD-ROM dictionaries

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

EBFILES=	${DISTNAME}${EXTRACT_SUFX}
LISTFILES=	appendix/LIST \
		appendix/LIST-ja
APPENDIXFILES=	appendix/cencro-1.0.tar.gz \
		appendix/chujiten-2.3.tar.gz \
		appendix/chujiten2-2.0.tar.gz \
		appendix/chujiten6-2.3.tar.gz \
		appendix/colloc-2.0.tar.gz \
		appendix/crownfj-2.0.tar.gz \
		appendix/crownfj2-1.0.tar.gz \
		appendix/crowngj-1.0.tar.gz \
		appendix/daihyakka-1.0.tar.gz \
		appendix/daijirin-2.0.tar.gz \
		appendix/dd75-2.0.tar.gz \
		appendix/gendai2000-1.0.tar.gz \
		appendix/genius-1.0.tar.gz \
		appendix/genius2-1.1.tar.gz \
		appendix/global-2.0.tar.gz \
		appendix/heritage-2.2.tar.gz \
		appendix/izumi-2.0.tar.gz \
		appendix/jitenban-2.4.tar.gz \
		appendix/jitenban97-2.1.tar.gz \
		appendix/kanjigen-2.0.tar.gz \
		appendix/kanjigen2-2.0.tar.gz \
		appendix/kojien-2.3.tar.gz \
		appendix/kojien2-2.0.tar.gz \
		appendix/kojien4-2.2.tar.gz \
		appendix/oxford-2.0.tar.gz \
		appendix/plus-2.0.tar.gz \
		appendix/readers-2.2.tar.gz \
		appendix/readers2-2.0.tar.gz \
		appendix/ruigigo-1.0.tar.gz \
		appendix/superdic98-1.0.tar.gz

DIST_SUBDIR=	eb

USE_PERL5=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-nls \
		--with-gettext-includes=${LOCALBASE}/include \
		--with-gettext-libraries=${LOCALBASE}/lib \
		--with-iconv-includes=${LOCALBASE}/include \
		--with-iconv-libraries=${LOCALBASE}/lib

APPENDIXDIR=	${DATADIR}/appendix

post-extract:
	${RM} -fr ${WRKSRC}/zlib
	${MKDIR} ${WRKDIR}/appendix
.for file in ${APPENDIXFILES}
	${TAR} --exclude CVS -C ${WRKDIR}/appendix -zxmf \
	  ${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor

post-install:
.for file in ${LISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${APPENDIXDIR}
.endfor
	${CP} -R ${WRKDIR}/appendix/ ${APPENDIXDIR}

.include <bsd.port.mk>
