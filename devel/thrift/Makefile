# New ports collection makefile for:	thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20090622
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Framework for scalable cross-language services development

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost \
		event-1.4:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	autoconf:262:env autoheader:262:env aclocal:19:env \
		automake:19:env libtool:15:env
USE_GNOME=	pkgconfig
USE_BZIP2=	yes
USE_GCC=	4.2+
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-boost=${LOCALBASE} --with-libevent=${LOCALBASE} \
		--enable-shared --enable-static --with-zlib
CONFIGURE_ENV+=	${MAKE_ENV}

# TODO: Add runtime auto-dependencies on erlang, perl, python, ruby, java.
# Not familiar with csharp, probably needs Mono.
CONFIGURE_ARGS+= \
		--without-csharp \
		--without-erlang \
		--without-java \
		--without-perl \
		--without-py \
		--without-ruby

.include <bsd.port.pre.mk>
#
# To roll snapshot: as bms: env BOOTSTRAP=defined make fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	787160		# svn tip at epoch 20090622
SVNROOT_URI=	http://svn.apache.org/repos/asf/incubator/thrift

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/trunk ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bms
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

do-patch:
	@${REINPLACE_CMD} 's,^pkgconfigdir = .*,pkgconfigdir=$${prefix}/libdata/pkgconfig,' ${WRKSRC}/lib/cpp/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ./bootstrap.sh)

post-install:
	@${LN} -sf ${PREFIX}/lib/libthrift.so.0 ${PREFIX}/lib/libthrift.so
	@${LN} -sf ${PREFIX}/lib/libthriftnb.so.0 ${PREFIX}/lib/libthriftnb.so
	@${LN} -sf ${PREFIX}/lib/libthriftz.so.0 ${PREFIX}/lib/libthriftz.so

# TODO: Documentation is not currently installed; requires TeX.

.include <bsd.port.post.mk>
