#Find NLopt library.
#The following variables are set
#
#NLopt_FOUND
#NLopt_INCLUDE_DIRS
#NLopt_LIBRARIES
#
#It searches the environment variable $NLopt_PATH automatically.

unset(NLopt_FOUND CACHE)
unset(NLopt_INCLUDE_DIRS CACHE)
unset(NLopt_LIBRARIES CACHE)
unset(NLopt_LIBRARIES_RELEASE CACHE)
unset(NLopt_LIBRARIES_DEBUG CACHE)

if($<LOWER_CASE:${CMAKE_BUILD_TYPE}> EQUAL "debug")
    set(NLopt_BUILD_TYPE DEBUG)
else()
    set(NLopt_BUILD_TYPE RELEASE)
endif()

find_path(NLopt_INCLUDE_DIRS nlopt.hpp
    $ENV{NLopt_PATH}
    $ENV{NLopt_PATH}/cpp/
    $ENV{NLopt_PATH}/include/
    ${CMAKE_PREFIX_PATH}/include/nlopt
    ${CMAKE_PREFIX_PATH}/include/
    /opt/local/include/
    /opt/local/include/nlopt/
    /usr/local/include/
    /usr/local/include/nlopt/
    /usr/include
    /usr/include/nlopt/
)

set(LIB_SEARCHDIRS 
    $ENV{NLopt_PATH}
    $ENV{NLopt_PATH}/cpp/
    $ENV{NLopt_PATH}/cpp/build/
    $ENV{NLopt_PATH}/lib/
    $ENV{NLopt_PATH}/lib/nlopt/
    ${CMAKE_PREFIX_PATH}/lib/
    ${CMAKE_PREFIX_PATH}/lib/nlopt/
    /opt/local/lib/
    /opt/local/lib/nlopt/
    /usr/local/lib/
    /usr/local/lib/nlopt/
    /usr/lib/nlopt
)

set(_deb_postfix "d")

find_library(NLopt_LIBRARIES_RELEASE nlopt ${LIB_SEARCHDIRS})
find_library(NLopt_LIBRARIES_DEBUG nlopt${_deb_postfix} ${LIB_SEARCHDIRS})

if(NLopt_LIBRARIES_${NLopt_BUILD_TYPE})
    set(NLopt_LIBRARIES "${NLopt_LIBRARIES_${NLopt_BUILD_TYPE}}")
else()
    set(NLopt_LIBRARIES "${NLopt_LIBRARIES_RELEASE}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NLopt
    "NLopt library cannot be found. Consider set NLopt_PATH environment variable"
    NLopt_INCLUDE_DIRS
    NLopt_LIBRARIES
)

mark_as_advanced(NLopt_INCLUDE_DIRS NLopt_LIBRARIES)

if(NLopt_FOUND)
    add_library(NLopt::nlopt UNKNOWN IMPORTED)
    set_target_properties(NLopt::nlopt PROPERTIES IMPORTED_LOCATION ${NLopt_LIBRARIES})
    set_target_properties(NLopt::nlopt PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${NLopt_INCLUDE_DIRS})
    if(NLopt_LIBRARIES_RELEASE AND NLopt_LIBRARIES_DEBUG)
        set_target_properties(NLopt::nlopt PROPERTIES
            IMPORTED_LOCATION_DEBUG          ${NLopt_LIBRARIES_DEBUG}
            IMPORTED_LOCATION_RELWITHDEBINFO ${NLopt_LIBRARIES_RELEASE}
            IMPORTED_LOCATION_RELEASE        ${NLopt_LIBRARIES_RELEASE}
            IMPORTED_LOCATION_MINSIZEREL     ${NLopt_LIBRARIES_RELEASE}
        )
    endif()
endif()
