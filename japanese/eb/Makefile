# New ports collection makefile for:	eb
# Date created:			20 Jan 1999
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	eb
PORTVERSION=	3.2.3
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/network/ndtp/eb/
DISTFILES=	${EBFILES} \
		${LISTFILES} \
		${APPENDIXFILES}
EXTRACT_ONLY=	${EBFILES}

PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	${DISTNAME}+.diff

MAINTAINER=	takamune@avrl.mei.co.jp

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

EBFILES=	${DISTNAME}${EXTRACT_SUFX}
LISTFILES=	appendix/LIST \
		appendix/LIST-ja
APPENDIXFILES=	appendix/cencro-1.0.tar.gz \
		appendix/chujiten-2.3.tar.gz \
		appendix/chujiten2-2.0.tar.gz \
		appendix/chujiten6-2.3.tar.gz \
		appendix/colloc-2.0.tar.gz \
		appendix/crownfj-2.0.tar.gz \
		appendix/daihyakka-1.0.tar.gz \
		appendix/daijirin-2.0.tar.gz \
		appendix/dd75-2.0.tar.gz \
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
		appendix/superdic98-1.0.tar.gz

DIST_SUBDIR=	eb

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-nls \
		--with-gettext-includes=${PREFIX}/include \
		--with-gettext-libraries=${PREFIX}/lib \
		--with-iconv-includes=${PREFIX}/include \
		--with-iconv-libraries=${PREFIX}/lib

INSTALLS_SHLIB=	yes

APPENDIXDIR=	${PREFIX}/share/eb/appendix

pre-configure:
	cd ${WRKSRC}; autoconf

post-install:
.for file in ${LISTFILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${APPENDIXDIR}
.endfor
.for file in ${APPENDIXFILES}
	${TAR} --no-same-owner --exclude CVS -C ${APPENDIXDIR} -zxmf\
	  ${DISTDIR}/${DIST_SUBDIR}/${file}
.endfor

.include <bsd.port.mk>
