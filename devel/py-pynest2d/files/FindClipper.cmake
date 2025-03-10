#Find Clipper library (http://www.angusj.com/delphi/clipper.php).
#The following variables are set
#
#CLIPPER_FOUND
#CLIPPER_INCLUDE_DIRS
#CLIPPER_LIBRARIES
#
#It searches the environment variable $CLIPPER_PATH automatically.

unset(CLIPPER_FOUND CACHE)
unset(CLIPPER_INCLUDE_DIRS CACHE)
unset(CLIPPER_LIBRARIES CACHE)
unset(CLIPPER_LIBRARIES_RELEASE CACHE)
unset(CLIPPER_LIBRARIES_DEBUG CACHE)

if($<LOWER_CASE:${CMAKE_BUILD_TYPE}> EQUAL "debug")
    set(CLIPPER_BUILD_TYPE DEBUG)
else()
    set(CLIPPER_BUILD_TYPE RELEASE)
endif()

find_path(CLIPPER_INCLUDE_DIRS clipper.hpp
    $ENV{CLIPPER_PATH}
    $ENV{CLIPPER_PATH}/cpp/
    $ENV{CLIPPER_PATH}/include/
    $ENV{CLIPPER_PATH}/include/polyclipping/
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/include/
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/include/polyclipping/
    ${CMAKE_PREFIX_PATH}/include/polyclipping
    ${CMAKE_PREFIX_PATH}/include/
    /opt/local/include/
    /opt/local/include/polyclipping/
    /usr/local/include/
    /usr/local/include/polyclipping/
    /usr/include
    /usr/include/polyclipping/
)

set(LIB_SEARCHDIRS 
    $ENV{CLIPPER_PATH}
    $ENV{CLIPPER_PATH}/cpp/
    $ENV{CLIPPER_PATH}/cpp/build/
    $ENV{CLIPPER_PATH}/lib/
    $ENV{CLIPPER_PATH}/lib/polyclipping/
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/lib/
    ${PROJECT_SOURCE_DIR}/python/pymesh/third_party/lib/polyclipping/
    ${CMAKE_PREFIX_PATH}/lib/
    ${CMAKE_PREFIX_PATH}/lib/polyclipping/
    /opt/local/lib/
    /opt/local/lib/polyclipping/
    /usr/local/lib/
    /usr/local/lib/polyclipping/
    /usr/lib/polyclipping
)

set(_deb_postfix "d")

find_library(CLIPPER_LIBRARIES_RELEASE polyclipping ${LIB_SEARCHDIRS})
find_library(CLIPPER_LIBRARIES_DEBUG polyclipping${_deb_postfix} ${LIB_SEARCHDIRS})

if(CLIPPER_LIBRARIES_${CLIPPER_BUILD_TYPE})
    set(CLIPPER_LIBRARIES "${CLIPPER_LIBRARIES_${CLIPPER_BUILD_TYPE}}")
else()
    set(CLIPPER_LIBRARIES "${CLIPPER_LIBRARIES_RELEASE}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Clipper
    "Clipper library cannot be found.  Consider set CLIPPER_PATH environment variable"
    CLIPPER_INCLUDE_DIRS
    CLIPPER_LIBRARIES
)

mark_as_advanced(CLIPPER_INCLUDE_DIRS CLIPPER_LIBRARIES)

if(CLIPPER_FOUND)
    add_library(Clipper::Clipper UNKNOWN IMPORTED)
    set_target_properties(Clipper::Clipper PROPERTIES IMPORTED_LOCATION ${CLIPPER_LIBRARIES})
    set_target_properties(Clipper::Clipper PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CLIPPER_INCLUDE_DIRS})
    if(CLIPPER_LIBRARIES_RELEASE AND CLIPPER_LIBRARIES_DEBUG)
        set_target_properties(Clipper::Clipper PROPERTIES
            IMPORTED_LOCATION_DEBUG          ${CLIPPER_LIBRARIES_DEBUG}
            IMPORTED_LOCATION_RELWITHDEBINFO ${CLIPPER_LIBRARIES_RELEASE}
            IMPORTED_LOCATION_RELEASE        ${CLIPPER_LIBRARIES_RELEASE}
            IMPORTED_LOCATION_MINSIZEREL     ${CLIPPER_LIBRARIES_RELEASE}
        )
    endif()
endif()
